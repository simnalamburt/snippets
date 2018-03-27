from functools import wraps

def decorate(f):
    '''
    데코레이터
    '''

    # 데코레이터 어트리뷰트
    decorate.MIN = 10
    decorate.MAX = 20

    @wraps(f)
    def wrapper(*args, **kwargs):
        print(f'{decorate.MIN} + {decorate.MAX} = {decorate.MIN + decorate.MAX}')
        return f(*args, **kwargs)
    return wrapper

@decorate
def main():
    print('ㅇㅅㅇ)~')

if __name__ == '__main__':
    main()
