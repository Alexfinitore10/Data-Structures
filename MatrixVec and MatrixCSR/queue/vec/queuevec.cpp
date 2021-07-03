
#include<iostream>
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueVec<Data>::QueueVec():Vector<Data>(5)
{

}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& lc):Vector<Data>(lc)
{
  testa = 0;
  coda = lc.Size()-1;
  stacksize = lc.Size();
  SwapVectors();
}

template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& q):Vector<Data>(q)
{
  stacksize = q.stacksize;
  testa = q.testa;
  coda = q.coda;
}

template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& q)noexcept:Vector<Data>(q)
{
  std::swap(stacksize, q.stacksize);
  std::swap(testa, q.testa);
  std::swap(coda, q.coda);
}

// template<typename Data>
// QueueVec<Data>::~QueueVec()
// {
//   Clear();
// }

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& q)
{
  Vector<Data>::operator=(q);
  stacksize = q.stacksize;
  testa = q.testa;
  coda = q.coda;
  return *this;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& q)noexcept
{
  Vector<Data>::operator=(q);
  std::swap(stacksize, q.stacksize);
  std::swap(testa, q.testa);
  std::swap(coda, q.coda);
  return *this;
}

template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& q)const noexcept
{
  if(stacksize == q.stacksize)
  {
    for(ulong i = 0; i<stacksize; ++i)
    {
      if(Elements[i] != q.Elements[i])
      {return false;}
    }
    return true;
  }else
    return false;
}

template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& q)const noexcept
{
  return !(*this == q);
}

template<typename Data>
void QueueVec<Data>::Enqueue(const Data& val)
{
  if(testa == (coda+1)%size)
  {
    SwapVectors();
  }
    Elements[coda]= val;
    coda = (coda+1)%size;
    stacksize++;
}

template<typename Data>
void QueueVec<Data>::Enqueue(Data&& val)noexcept
{
  if(testa == (coda+1)%size)
  {
    SwapVectors();
  }
    std::swap(Elements[coda], val);
    coda = (coda+1)%size;
    stacksize++;
}

template<typename Data>
Data& QueueVec<Data>::Head()
{
  if(testa==coda)
  {
    throw std::length_error("length_error");
  }else
  return Elements[testa];
}

template<typename Data>
void QueueVec<Data>::Dequeue()
{
  if(testa==coda)
  {
    testa = 0;
    coda = 0;
    throw std::length_error("length_error");
  }else
  testa=(testa+1)%size;
  stacksize--;
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue()
{
  Data a = Head();
  Dequeue();
  return a;
}

template<typename Data>
bool QueueVec<Data>::Empty()const noexcept
{
   return (testa == coda);
}

template<typename Data>
bool QueueVec<Data>::Full()
{
  return (testa-1 == coda);
}

template<typename Data>
ulong QueueVec<Data>::Size()const noexcept
{
  return stacksize;
}

template<typename Data>
void QueueVec<Data>::Clear()
{
  Vector<Data>::Clear();
  stacksize = 0;
  testa = 0;
  coda = 0;
}

template<typename Data>
void QueueVec<Data>::Expand()
{
  Vector<Data>::Resize(size*2);
}

template<typename Data>
void QueueVec<Data>::Reduce()
{
    Vector<Data>::Resize(size/2);
}

template<typename Data>
void QueueVec<Data>::SwapVectors()
{
  ulong app=0;
 Data* TmpElements = new Data[size*2]{};


 while(app<size)
 {
  for (ulong i = testa; i < size ; i++) {
    std::swap(Elements[i],TmpElements[app]);
    app++;
  }
  if(app<size)
    {
      for (ulong z = 0; z < coda ; z++) {
        std::swap(Elements[z],TmpElements[app]);
        app++;
      }
    }
}

std::cout << "stacksize :"<< stacksize << '\n';
  std::swap(Elements, TmpElements);
  delete[] TmpElements;
  testa = 0;
  size = size*2;
  coda=stacksize;
}


/* ************************************************************************** */

}
