#!/usr/bin/env python3
import re
from importlib.util import find_spec

def all_keys(Bucket, Prefix, Regex):
    '''
    특정 S3 버킷 안에 있는 모든 키들을 제네레이터로 반환해주는 함수.
    boto3나 boto 둘중 하나만 깔려있으면 작동한다.

    @param Bucket: 버킷 이름
    @param Prefix: 프리픽스
    @param Regex: 이 정규식을 만족하는 키만 반환함
    @return: 조건을 만족하는 파일들을 담은 제네레이터
    '''

    program = re.compile(Regex)
    if find_spec('boto3'):
        import boto3
        s3 = boto3.client('s3')
        kwargs = { 'Bucket': Bucket, 'Prefix': Prefix }
        while True:
            resp = s3.list_objects_v2(**kwargs)
            yield from (obj['Key'] for obj in resp['Contents'] if program.match(obj['Key']))
            token = resp.get('NextContinuationToken', None)
            if token is None:
                break
            kwargs['ContinuationToken'] = token
    else:
        import boto
        conn = boto.connect_s3()
        bucket = conn.get_bucket(Bucket)
        yield from (key.name for key in bucket.list(prefix=Prefix) if program.match(key.name))

# 실행 예시
for key in all_keys(
        Bucket='ryft-public-sample-data',
        Prefix='ODBC',
        Regex=r'^.*\.gz$'):
    print(key)
