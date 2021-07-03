
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& lc):List<Data>(lc)
{
  
}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& q):List<Data>(q)
{

}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& q)noexcept:List<Data>(std::move(q))
{

}

template<typename Data>
QueueLst<Data>::~QueueLst()
{
  Clear();
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& q)
{
  List<Data>::operator=(q);
  return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& q)noexcept
{
  List<Data>::operator=(q);
  return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& q)const noexcept
{
  return List<Data>::operator==(q);
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& q)const noexcept
{
  return !(*this == q);
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& val)
{
  List<Data>::InsertAtBack(val);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& val)noexcept
{
  List<Data>::InsertAtBack(val);
}

template<typename Data>
Data& QueueLst<Data>::Head()
{
  return List<Data>::Front();
}

template<typename Data>
void QueueLst<Data>::Dequeue()
{
  List<Data>::RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue()
{

  return List<Data>::FrontNRemove();
}

template<typename Data>
void QueueLst<Data>::Clear()
{
  List<Data>::Clear();
}

/* ************************************************************************** */

}
