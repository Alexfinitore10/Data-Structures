
namespace lasd {

/* ************************************************************************** */

template<typename Data>
MatrixVec<Data>::MatrixVec(ulong riga, ulong colonna)
{
  Vector<Data>::Resize(riga*colonna);
  row = riga;
  column = colonna;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec& in):Vector<Data>(in)
{
  row = in.row;
  column = in.column;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec&& in)noexcept:Vector<Data>(std::move(in))
{
  std::swap(row, in.row);
  std::swap(column, in.column);
}


template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec& in)
{
  Vector<Data>::operator=(in);
  row= in.row;
  column = in.column;
  return *this;
}

template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec&& in)noexcept
{
  Vector<Data>::operator=(std::move(in));
  std::swap(row, in.row);
  std::swap(column, in.column);
  return *this;
}

template<typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec& in)const
{
  if(row == in.row && column == in.column)
  {
    if(Vector<Data>::operator==(in))
    {
      return true;
    }else return false;
  }else return false;
}

template<typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec& in)const
{
  return !(*this==in);
}

template<typename Data>
void MatrixVec<Data>::RowResize(ulong riga)
{
  if(riga == 0)
  {
    Vector<Data>::Clear();
    row = 0;
  }else if(riga<row){
    Data* tmp = new Data[column*riga] {};
    uint i = 0;
    uint j = 0;
    for(; i<riga; i++)
    {
        for(; j<column; j++)
        {
            std::swap(tmp[i*column+j],Elements[i*column+j]);
        }
        j=0;
    }
    std::swap(tmp, Elements);
    row = riga;
    size = column * row;
    delete[] tmp;
  }else if (riga > row)
  {
    Data* tmp = new Data[column*riga] {};
    uint i = 0;
    uint j = 0;
    for(; i<row; i++)
    {
        for(; j<column; j++)
        {
            std::swap(tmp[i*column+j],Elements[i*column+j]);
        }
        j=0;
    }
    std::swap(tmp, Elements);
    row = riga;
    size = column * row;
    delete[] tmp;
  }
  // Vector<Data>::Resize(riga * column);
  // row = riga;
}

template<typename Data>
void MatrixVec<Data>::ColumnResize(ulong colonne)
{
  if(colonne == 0)
  {
    Vector<Data>::Clear();
    column = 0;
  }else if (colonne > column)
  {
    Data* tmp = new Data[colonne*row] {};
    for(ulong i = 0; i<row; i++)
      {
          for(ulong j = 0; j<column; j++)
        {
            std::swap(tmp[i*colonne+j],Elements[i*column+j]);
        }
      }
    std::swap(tmp, Elements);
    column = colonne;
    size = column * row;
    delete[] tmp;
  }else if (colonne < column)
  {
    Data* tmp = new Data[colonne*row] {};

    for(ulong i = 0; i<row; i++)
      {
          for(ulong j = 0; j<colonne; j++)
        {
            std::swap(tmp[i*colonne+j],Elements[i*column+j]);
        }
      }
    std::swap(tmp, Elements);
    column = colonne;
    size = column * row;
    delete[] tmp;
  }
}

template<typename Data>
bool MatrixVec<Data>::ExistsCell(const ulong riga, const ulong colonna)const noexcept
{
  if(riga < row && colonna < column)
  {
    return true;
  }else return false;
}

template<typename Data>
Data& MatrixVec<Data>::operator()(ulong riga, ulong colonna)
{
  if(ExistsCell(riga, colonna))
  {
    return Elements[riga*column+colonna];
  }else throw std::out_of_range("out_of_range nell'operatore ()");
}

template<typename Data>
const Data& MatrixVec<Data>::operator()(const ulong riga, const ulong colonna)const
{
  if(ExistsCell(riga, colonna))
  {
    return Elements[riga*column+colonna];
  }else throw std::out_of_range("out_of_range nell'operatore ()");
}

template<typename Data>
void MatrixVec<Data>::Clear()
{
  Vector<Data>::Clear();
  row = 0;
  column = 0;
}

template<typename Data>
void MatrixVec<Data>::MapPreOrder(const MapFunctor f,void* a)
{
  Vector<Data>::MapPreOrder(f, a);
}

template<typename Data>
void MatrixVec<Data>::MapPostOrder(const MapFunctor f,void* a)
{
  Vector<Data>::MapPostOrder(f, a);
}

template<typename Data>
void MatrixVec<Data>::FoldPreOrder(const FoldFunctor f,const void* a , void* d)const
{
  Vector<Data>::FoldPreOrder(f, a, d);
}

template<typename Data>
void MatrixVec<Data>::FoldPostOrder(const FoldFunctor f,const void* a , void* d)const
{
  Vector<Data>::FoldPostOrder(f, a, d);
}

/* ************************************************************************** */

}
