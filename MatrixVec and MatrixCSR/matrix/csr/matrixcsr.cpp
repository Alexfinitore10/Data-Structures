

namespace lasd {

/* ************************************************************************** */

template<typename Data>
MatrixCSR<Data>::MatrixCSR()
{
  vett.Resize(1);
  vett[0] = &head;
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(ulong riga, ulong colonna)
{
  row = riga;
  column = colonna;
  vett.Resize(riga+1);
  for(ulong i = 0; i< vett.Size(); ++i)
  {
    vett[i] = &head;
  }
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& in):MatrixCSR<Data>(in.row, in.column)
{
  for(ulong i = 0; i<in.row; ++i)
  {
    for(Node** lnk = in.vett[i]; lnk != in.vett[i+1]; lnk = &((*lnk)->link))
    {
      (*this)(i, (*lnk)->dato.second) = (*lnk)->dato.first;
    }
  }
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR&& in)noexcept: List<std::pair<Data,ulong>>(std::move(in))
{
  std::swap(vett, in.vett);
  std::swap(column, in.column);
  std::swap(row, in.row);
  for(ulong i = 0; i< vett.Size() && &in.head == vett[i]; ++i)
  {
    vett[i] = &head;
  }

  for(ulong i = 0; i< in.vett.Size() && &head == in.vett[i]; ++i)
  {
    in.vett[i] = &in.head;
  }
}

template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR& in)
{
  MatrixCSR<Data>* tmp = new MatrixCSR(in);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR&& in)noexcept
{
  std::swap(vett, in.vett);
  std::swap(column, in.column);
  std::swap(row, in.row);
  List<std::pair<Data,ulong>>::operator=(std::move(in));
  for(ulong i = 0; i< vett.Size() && &in.head == vett[i]; ++i)
  {
    vett[i] = &head;
  }

  for(ulong i = 0; i< in.vett.Size() && &head == in.vett[i]; ++i)
  {
    in.vett[i] = &in.head;
  }

  return *this;
}

template<typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR& in)const noexcept
{
  if(row == in.row && column == in.column)
  {
    for(ulong i = 0; i<row; ++i)
    {
      Node** we = vett[i];
      Node** we2 = in.vett[i];
      while(we != vett[i+1] && we2 != in.vett[i+1])
      {
        if((*we)->dato != (*we2)->dato)
        {
          return false;
        }else
        we = &(*we)->link;
        we2 = &(*we2)->link;
      }
      if(we != vett[i+1] || we2 != in.vett[i+1])
      {
        return false;
      }
    }
    return true;
  }else return false;
}

template<typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR& in)const noexcept
{
  return !(*this == in);
}

template<typename Data>
void MatrixCSR<Data>::RowResize(ulong riga)
{
  if(riga == 0)
  {
    List<std::pair<Data,ulong>>::Clear();
    vett.Resize(1);
    row = riga;
  }else if (riga < row)
  {
    Node* a = *vett[riga];
    ulong conta = 0;
    for(Node* b = a;b != nullptr; b = b->link)
    {
      conta++;
    }
    delete a;
    *vett[riga] = nullptr;
    row = riga;
    size = size - conta;
    vett.Resize(riga+1);
  }else if(riga>row)
  {
    vett.Resize(riga+1);
    Node** ptr = vett[row];
    for(ulong i = row+1; i< vett.Size(); i++)
    {
      vett[i] = ptr;
    }
    row = riga;
  }
}

template<typename Data>
void MatrixCSR<Data>::ColumnResize(ulong colonna)
{
  if(colonna == 0)
  {
    List<std::pair<Data,ulong>>::Clear();
  }else if(colonna > column)
  {
    column = colonna;
  }else if(colonna< column)
  {
    ulong index = 1;
    Node** ptr = vett[0];
    while(index <= row)
    {
      while(ptr != vett[index] && (*ptr)->dato.second < colonna)
      {
        ptr = &((*ptr)->link);
      }
      Node** t = vett[index];
      if(ptr != t)
      {
        Node* tmp = *ptr;
        *ptr = *t;
        *t = nullptr;
        for(Node* temp = tmp; temp != nullptr; temp = temp->link)
        {
          size--;
        }
        delete tmp;
        for(int i = index; i< vett.Size() && vett[i] == t; i++)
        {
          vett[i] = ptr;
        }
      }
      index++;
    }
  }
  column = colonna;
}

template<typename Data>
bool MatrixCSR<Data>::ExistsCell(const ulong riga, const ulong colonna)const noexcept
{
  if(riga < row && colonna < column)
  {
    Node** nd = vett[riga];
    if(nd != vett[riga+1])
    {
      while(nd != vett[riga+1])
      {
        if((*nd)->dato.second == colonna)
        {
          return true;
        }else
        {
          nd = &((*nd)->link);
        }
      }
      return false;
    }else
    {
      return false;
    }
  }else return false;
}

template<typename Data>
const Data& MatrixCSR<Data>::operator()(const ulong riga, const ulong colonna)const
{
  if(riga < row && colonna < column)
  {
    Node** nd = vett[riga];
    if(nd != vett[riga+1])
    {
      while(nd != vett[riga+1])
      {
        if((*nd)->dato.second == colonna)
        {
          return (*nd)->dato.first;
        }else
        {
          nd = &((*nd)->link);
        }
      }throw std::length_error("length_error");
    }else throw std::length_error("length_error");
  }else throw std::out_of_range("Out of range nel ()");
}

template<typename Data>
Data& MatrixCSR<Data>::operator()(ulong riga,ulong colonna)
{
  if(riga < row && colonna < column)
  {
    Node** nd = vett[riga];
    if(nd != vett[riga+1])
    {
      while(nd != vett[riga+1])
      {
        if((*nd)->dato.second == colonna)
        {
          return (*nd)->dato.first;
        }else if((*nd)->dato.second < colonna)
        {
          nd = &((*nd)->link);
        }else if((*nd)->dato.second > colonna)
        {
          Node* tmp = new Node();
          tmp->dato.second = colonna;
          tmp->link = *nd;
          *nd= tmp;
          size++;
          return tmp->dato.first;
        }
      }//fuori dal while
      Node* tmp = new Node();
      size++;
      tmp->dato.second = colonna;
      tmp->link = *nd;
      *nd = tmp;
      for(uint i= riga+1; i<vett.Size() && vett[i] == nd; i++)
      {
        vett[i] = &tmp->link;
      }
      return tmp->dato.first;
    }else//caso in cui la riga non esiste
    {
      Node* tmp = new Node();
      size++;
      tmp->dato.second = colonna;
      tmp->link = *nd;
      *nd = tmp;
      for(uint i= riga+1; i<vett.Size() && vett[i] == nd; i++)
      {
        vett[i] = &tmp->link;
      }
      return tmp->dato.first;
    }
  }else throw std::out_of_range("Out of range nel ()");
}

template<typename Data>
void MatrixCSR<Data>::Clear()
{
  List<std::pair<Data,ulong>>::Clear();
  vett.Resize(1);
  row = 0;
  column = 0;
}

template<typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun,void* par)
{
  List<std::pair<Data,ulong>>::MapPreOrder(
    [&fun](std::pair<Data,ulong>& datx, void* parx) {fun(datx.first, parx);}
    , par);
}

template<typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun,void* par)
{
  List<std::pair<Data,ulong>>::MapPostOrder(
    [&fun](std::pair<Data,ulong>& datx, void* parx) {fun(datx.first, parx);}
    , par);
}

template<typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun,const void* par, void* acc)const
{
  List<std::pair<Data,ulong>>::FoldPreOrder(
    [&fun](const std::pair<Data,ulong>& datx,const void* parx, void* accx) {fun(datx.first, parx, accx);}
    , par, acc);
}

template<typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun,const void* par, void* acc)const
{
  List<std::pair<Data,ulong>>::FoldPostOrder(
    [&fun](const std::pair<Data,ulong>& datx,const void* parx, void* accx) {fun(datx.first, parx, accx);}
    , par, acc);
}

/* ************************************************************************** */

}
