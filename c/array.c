int main()
{
  int array[10];
  void* p1 = array + 1;
  void* p2 = &array[1];
  return 0;
}
