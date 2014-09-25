def depth0():
  print("depth0 호출됨")
  depth1()
  print("depth0 끝남")

def depth1():
  print("depth0 안의 depth1 호출됨")
  depth2()
  print("depth0 안의 depth1 끝남")

def depth2():
  print("depth0 안의 depth1 안의 depth2 호출됨")
  print("depth0 안의 depth1 안의 depth2 끝남")

depth0()
