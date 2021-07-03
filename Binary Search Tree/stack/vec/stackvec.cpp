
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec():Vector<Data>(1)
{
}


template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& lc):Vector<Data>(lc)
{
  stacksize = lc.Size();
}

template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stk):Vector<Data>(stk)
{
  // size = stk.size;
  stacksize = stk.stacksize;
}

template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stk)noexcept:Vector<Data>(std::move(stk))
{
  // std::swap(size, stk.size);
  std::swap(stacksize,stk.stacksize);
}

template<typename Data>
StackVec<Data>::~StackVec()
{
  Clear();
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stk)
{
  Vector<Data>::operator=(stk);
  // size = stk.size;
  stacksize = stk.stacksize;
  return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=( StackVec<Data>&& stk) noexcept
{
  Vector<Data>::operator=(stk);
  stacksize = stk.stacksize;
  return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stk) const
{

  return Vector<Data>::operator==(stk);
}

template<typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stk) const
{
  return !(*this == stk);
}

template<typename Data>
void StackVec<Data>::Push(const Data& dat)
{
  if(stacksize == size)
  {
    Expand();
    Elements[stacksize] = dat;
    stacksize++;
  }else
  {
    Elements[stacksize] = dat;
    stacksize++;
  }
  // std::cout << Elements[stacksize-1]<< "  indice:" <<stacksize-1 << '\n';
}

template<typename Data>
void StackVec<Data>::Push(Data&& dat)noexcept
{
  if(stacksize >= size)
  {
    Expand();
    std::swap(Elements[stacksize], dat);
    stacksize++;
    // std::cout << Elements[stacksize-1]<< "  indice:" <<stacksize-1 << '\n';
  }else
  {
    std::swap(Elements[stacksize], dat);
    stacksize++;
  }
}

template<typename Data>
Data& StackVec<Data>::Top()
{
  if(stacksize != 0)
  {
    Data& a = Elements[stacksize-1];
    return a;
  }else
    throw std::length_error("length_error");
}

template<typename Data>
void StackVec<Data>::Pop()//da rifare
{
  if(stacksize != 0)
  {
    stacksize--;
  }else
  {
    throw std::length_error("length_error");
  }
}

template<typename Data>
Data StackVec<Data>::TopNPop()
{
  Data a = Top();
  Pop();
  return a;
}

template<typename Data>
void StackVec<Data>::Expand()
{
  Vector<Data>::Resize(size*2);
}

template<typename Data>
void StackVec<Data>::Reduce()
{
  Vector<Data>::Resize(size/2);
}

template<typename Data>
void StackVec<Data>::Clear()
{
  Vector<Data>::Clear();
  size = 0;
  stacksize = 0;
}

template<typename Data>
ulong StackVec<Data>::Size()const noexcept
{
  return stacksize;
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
  return (stacksize == 0);
}

/* ************************************************************************** */

}
