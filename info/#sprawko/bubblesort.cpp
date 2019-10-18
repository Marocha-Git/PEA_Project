//algorytm sortowania babelkowego
//R. I.
void BubbleSort(int tab[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1; j++)
    {
      if (tab[j] > tab[j + 1])
        swap(tab[j], tab[j + 1]);
      //Operacja typu zamien
    }
  }
  cout << "Zakonczono sortowanie\n";
}
