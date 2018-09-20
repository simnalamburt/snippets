from importlib.util import find_spec

def download_file(bucket, key, filename):
    '''
    특정 S3 오브젝트를 주어진 경로로 다운받아주는 함수. boto3나 boto 둘중 하나만
    깔려있으면 작동한다.

    Reference: https://github.com/simnalamburt/snippets/blob/master/python/s3-download-file.py
    '''

    if find_spec('boto3'):
        download_file_boto3(bucket, key, filename)
    elif find_spec('boto'):
        download_file_boto2(bucket, key, filename)
    else:
        raise ModuleNotFoundError("Module 'boto3' or 'boto' is required")

def download_file_boto3(bucket, key, filename):
    import boto3
    boto3.client('s3').download_file(bucket, key, filename)

def download_file_boto2(bucket, key, filename):
    import boto
    from boto.s3.bucket import Bucket
    from boto.s3.key import Key
    conn = boto.connect_s3()
    Key(Bucket(conn, bucket), key).get_contents_to_filename(filename)

# 실행 예시
if __name__ == '__main__':
    download_file(
        'paperhub',
        'f7502ec8f175e7b9ae4612429c7ecda9.pdf',
        'output.pdf')
