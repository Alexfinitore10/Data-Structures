
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& var):List<Data>(var)
{

}

template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stk):List<Data>(stk)
{
}

template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stk) noexcept:List<Data>(stk)
{
}

template<typename Data>
StackLst<Data>::~StackLst()
{
  Clear();
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stk)
{
  List<Data>::operator=(stk);
  return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stk)noexcept
{
  List<Data>::operator=(stk);
  return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stk)const noexcept
{
  return List<Data>::operator==(stk);
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stk)const noexcept
{
  return !(*this == stk);
}

template<typename Data>
void StackLst<Data>::Push(const Data& dat)
{
  List<Data>::InsertAtFront(dat);
}

template<typename Data>
void StackLst<Data>::Push(Data&& dat)noexcept
{
  List<Data>::InsertAtFront(dat);
}

template<typename Data>
Data& StackLst<Data>::Top()
{
  return List<Data>::Front();
}

template<typename Data>
void StackLst<Data>::Pop()
{
  List<Data>::RemoveFromFront();
}

template<typename Data>
Data StackLst<Data>::TopNPop()
{
  return List<Data>::FrontNRemove();
}

template<typename Data>
void StackLst<Data>::Clear()
{
  List<Data>::Clear();
}


/* ************************************************************************** */

}
