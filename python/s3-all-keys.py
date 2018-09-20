import re
from importlib.util import find_spec

def all_keys(bucket, prefix, regex):
    '''
    특정 S3 버킷 안에 있는 모든 키들을 제네레이터로 반환해주는 함수.
    boto3나 boto 둘중 하나만 깔려있으면 작동한다.

    Reference: https://github.com/simnalamburt/snippets/blob/master/python/s3-all-keys.py

    @param bucket: 버킷 이름
    @param prefix: 프리픽스
    @param regex: 이 정규식을 만족하는 키만 반환함
    @return: 조건을 만족하는 파일들을 담은 제네레이터
    '''

    program = re.compile(regex)
    if find_spec('boto3'):
        import boto3
        s3 = boto3.client('s3')
        kwargs = { 'Bucket': bucket, 'Prefix': prefix }
        while True:
            resp = s3.list_objects_v2(**kwargs)
            yield from (obj['Key'] for obj in resp['Contents'] if program.match(obj['Key']))
            token = resp.get('NextContinuationToken', None)
            if token is None:
                break
            kwargs['ContinuationToken'] = token
    elif find_spec('boto'):
        import boto
        yield from (obj.name for obj
            in boto.connect_s3().get_bucket(bucket).list(prefix=prefix)
            if program.match(obj.name))
    else:
        raise ModuleNotFoundError("Module 'boto3' or 'boto' is required")

# 실행 예시
if __name__ == '__main__':
    for key in all_keys('ryft-public-sample-data', 'ODBC', r'^.*\.gz$'):
        print(key)
