
namespace lasd {

/* ************************************************************************** */

template<typename Data>
ulong Matrix<Data>::RowNumber()const noexcept
{
  return row;
}

template<typename Data>
ulong Matrix<Data>::ColumnNumber()const noexcept
{
  return column;
}

/* ************************************************************************** */

}
