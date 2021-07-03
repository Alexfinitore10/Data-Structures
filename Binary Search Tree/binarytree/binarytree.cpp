
#include "../queue/lst/queuelst.hpp"

namespace lasd {

/* ************************************************************************** */

  template<typename Data>
  bool BinaryTree<Data>::Node::operator==(const Node& in) const noexcept
  {
    if(this!=nullptr && &in!=nullptr){
    if(IsLeaf() && in.IsLeaf()){
      return (Element() == in.Element());
    }else if(HasLeftChild() && in.HasLeftChild() && HasRightChild() && in.HasRightChild()){
      return (Element()==in.Element() && LeftChild()==in.LeftChild() && RightChild() == in.RightChild());
    }else if(HasLeftChild() && in.HasLeftChild()){
      return (Element()==in.Element() && LeftChild()==in.LeftChild());
    }else if(HasRightChild() && in.HasRightChild()){
      return (Element()==in.Element() && RightChild() == in.RightChild());
    }else return false;
  }else if(this==nullptr && &in==nullptr){
    return true;
  }else return false;
  }

  template<typename Data>
  bool BinaryTree<Data>::Node::operator!=(const Node& nodo) const noexcept
  {
    return !(*this == nodo);
  }

  template<typename Data>
  bool BinaryTree<Data>::operator==(const BinaryTree& nodo) const noexcept
  {
    if(size == nodo.size)
    {
      return(Root() == nodo.Root());
    }else return false;
  }

  template<typename Data>
  bool BinaryTree<Data>::operator!=(const BinaryTree& nodo) const noexcept
  {
    return !(*this==nodo);
  }

  template<typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& in)
  {
    if(in.Size() != 0)
    {
      curr = &in.Root();
    }
  }

  template<typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& in)
  {
    curr = in.curr;
    stk = in.stk;
  }

  template<typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
  }

  template<typename Data>
  BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& in)
  {
    BTPreOrderIterator<Data>* temp = new BTPreOrderIterator<Data>(in);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  template<typename Data>
  BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
    return *this;
  }

  template<typename Data>
  bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& in)const noexcept
  {
    if(curr == in.curr && stk == in.stk)
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& in)const noexcept
  {
    return !(*this==in);
  }

  template<typename Data>
  Data& BTPreOrderIterator<Data>::operator*()const
  {
    if(curr == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else return curr->Element();
  }

  template<typename Data>
  bool BTPreOrderIterator<Data>::Terminated()const noexcept
  {
    return (curr == nullptr);
  }

  template<typename Data>
  ForwardIterator<Data>& BTPreOrderIterator<Data>::operator++()
  {
    if(Terminated())
    {
      throw std::out_of_range("out_of_range");
    }
    if(curr->HasRightChild())
    {
      stk.Push(&curr->RightChild());
    }
    if(curr->HasLeftChild())
    {
      stk.Push(&curr->LeftChild());
    }

    if(stk.Empty())
    {
      curr = nullptr;
    }else{
      curr = stk.TopNPop();
    }

    return *this;
  }

  template<typename Data>
  typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::MostLeafLeftNode(typename BinaryTree<Data>::Node& in)
  {
    if(in.HasLeftChild())
    {
      stk.Push(&in);
      return MostLeafLeftNode(in.LeftChild());
    }else if(in.HasRightChild())
    {
      stk.Push(&in);
      return MostLeafLeftNode(in.RightChild());
    }else return &in;
  }

  template<typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& in)
  {
    if(in.Size() != 0)
    {
      curr = MostLeafLeftNode(in.Root());
    }
  }

  template<typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& in)
  {
    curr = in.curr;
    stk = in.stk;
  }

  template<typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& in) noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
  }

  template<typename Data>
  BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& in)
  {
    BTPostOrderIterator<Data>* temp = new BTPostOrderIterator<Data>(in);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  template<typename Data>
  BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
    return *this;
  }

  template<typename Data>
  bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& in)const noexcept
  {
    if(curr == in.curr && stk == in.stk)
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& in)const noexcept
  {
    return !(*this == in);
  }

  template<typename Data>
  Data& BTPostOrderIterator<Data>::operator*()const
  {
    if(curr == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else return curr->Element();
  }

  template<typename Data>
  bool BTPostOrderIterator<Data>::Terminated()const noexcept
  {
    return (curr == nullptr);
  }

  template<typename Data>
  ForwardIterator<Data>& BTPostOrderIterator<Data>::operator++()
  {
    if(Terminated())
    {
      throw std::out_of_range("out_of_range");
    }
    if(!stk.Empty() && stk.Top()->HasLeftChild())
    {
        if(&stk.Top()->LeftChild().Element() == &curr->Element())
        {
          if(stk.Top()->HasRightChild())
          {
            stk.Push(MostLeafLeftNode(stk.Top()->RightChild()));
          }
        }
    }

    if(stk.Empty())
    {
      curr = nullptr;
    }else{
      curr = stk.TopNPop();
    }

    return *this;
  }

  template<typename Data>
  typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::MostLeftNode(typename BinaryTree<Data>::Node& in)
  {
    if(in.HasLeftChild())
    {
      stk.Push(&in);
      return MostLeftNode(in.LeftChild());
    }else
    {
      return &in;
    }
  }

  template<typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& in)
  {
    if(in.Size() != 0)
    {
      curr = MostLeftNode(in.Root());
    }
  }

  template<typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& in)
  {
    curr = in.curr;
    stk = in.stk;
  }

  template<typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
  }

  template<typename Data>
  BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& in)
  {
    BTInOrderIterator<Data>* temp = new BTInOrderIterator<Data>(in);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  template<typename Data>
  BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(stk, in.stk);
    return *this;
  }

  template<typename Data>
  bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& in)const noexcept
  {
    if(curr == in.curr && stk == in.stk)
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& in)const noexcept
  {
    return !(*this == in);
  }

  template<typename Data>
  Data& BTInOrderIterator<Data>::operator*()const
  {
    if(curr == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else return curr->Element();
  }

  template<typename Data>
  bool BTInOrderIterator<Data>::Terminated()const noexcept
  {
    return (curr == nullptr);
  }

  template<typename Data>
  ForwardIterator<Data>& BTInOrderIterator<Data>::operator++()
  {
    if(Terminated())
    {
      throw std::out_of_range("out_of_range");
    }

    if(curr->HasRightChild())
    {
      stk.Push(MostLeftNode(curr->RightChild()));
    }

    if(stk.Empty())
    {
      curr = nullptr;
    }else{
      curr = stk.TopNPop();
    }

    return *this;
  }

  template<typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& in)
  {
    if(in.Size() != 0)
    {
      curr = &in.Root();
    }
  }

  template<typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& in)
  {
    curr = in.curr;
    queue = in.queue;
  }

  template<typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(queue, in.queue);
  }

  template<typename Data>
  BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& in)
  {
    BTBreadthIterator<Data>* temp = new BTBreadthIterator<Data>(in);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  template<typename Data>
  BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& in)noexcept
  {
    std::swap(curr, in.curr);
    std::swap(queue, in.queue);
    return *this;
  }

  template<typename Data>
  bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& in)const noexcept
  {
    if(curr == in.curr && queue == in.queue)
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& in)const noexcept
  {
    return !(*this == in);
  }

  template<typename Data>
  Data& BTBreadthIterator<Data>::operator*()const
  {
    if(curr == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else return curr->Element();
  }

  template<typename Data>
  bool BTBreadthIterator<Data>::Terminated()const noexcept
  {
    return (curr == nullptr);
  }

  template<typename Data>
  ForwardIterator<Data>& BTBreadthIterator<Data>::operator++()
  {
    if(Terminated())
    {
      throw std::out_of_range("out_of_range");
    }

    if(curr->HasLeftChild())
    {
      queue.Enqueue(&curr->LeftChild());
    }

    if(curr->HasRightChild())
    {
      queue.Enqueue(&curr->RightChild());
    }

    if(queue.Empty())
    {
      curr = nullptr;
    }else{
      curr = queue.HeadNDequeue();
    }

    return *this;
  }
  template<typename Data>
  void BinaryTree<Data>::MapPreOrder(const MapFunctor mp, void* v)
  {
    if(&Root()!= nullptr)
    {
      MapPreOrder(mp, v, Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::MapPostOrder(const MapFunctor mp, void* v)
  {
    if(&Root()!= nullptr)
    {
      MapPostOrder(mp, v, Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldPreOrder(const FoldFunctor mp,const void* v, void* c)const
  {
    if(&Root()!= nullptr)
    {
      FoldPreOrder(mp, v, c,Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldPostOrder(const FoldFunctor mp,const void* v, void* c)const
  {
    if(&Root()!= nullptr)
    {
      FoldPostOrder(mp, v, c,Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::MapInOrder(const MapFunctor mp, void* v)
  {
    if(&Root()!= nullptr)
    {
      MapInOrder(mp, v, Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldInOrder(const FoldFunctor mp,const void* v, void* c)const
  {
    if(&Root()!= nullptr)
    {
      FoldInOrder(mp, v, c,Root());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::MapBreadth(const MapFunctor mp, void* v)
  {
    lasd::QueueLst<Node*> q;
    Node* curr = &Root();
    q.Enqueue(curr);
    while(!q.Empty())
    {
      curr = q.HeadNDequeue();
      mp(curr->Element(), v);
      if(curr->HasLeftChild())
      {
        q.Enqueue(&curr->LeftChild());
      }
      if(curr->HasRightChild())
      {
        q.Enqueue(&curr->RightChild());
      }
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldBreadth(const FoldFunctor mp,const void* v, void* c)const
  {
    lasd::QueueLst<Node*> q;
    Node* curr = &Root();
    q.Enqueue(curr);
    while(!q.Empty())
    {
      curr = q.HeadNDequeue();
      mp(curr->Element(), v, c);
      if(curr->HasLeftChild())
      {
        q.Enqueue(&curr->LeftChild());
      }
      if(curr->HasRightChild())
      {
        q.Enqueue(&curr->RightChild());
      }
    }
  }

  template<typename Data>
  void BinaryTree<Data>::MapPreOrder(const MapFunctor mp, void* v, Node& nodo)
  {
    mp(nodo.Element(), v);
    if(nodo.HasLeftChild())
    {
      MapPreOrder(mp, v, nodo.LeftChild());
    }
    if(nodo.HasRightChild())
    {
      MapPreOrder(mp, v, nodo.RightChild());
    }
  }
  template<typename Data>
  void BinaryTree<Data>::MapPostOrder(const MapFunctor mp, void* v, Node& nodo)
  {
    if(nodo.HasLeftChild())
    {
      MapPostOrder(mp, v, nodo.LeftChild());
    }
    if(nodo.HasRightChild())
    {
      MapPostOrder(mp, v, nodo.RightChild());
    }
    mp(nodo.Element(), v);
  }

  template<typename Data>
  void BinaryTree<Data>::FoldPreOrder(const FoldFunctor mp,const void* v, void* c, Node& nodo)const
  {
    mp(nodo.Element(), v, c);
    if(nodo.HasLeftChild())
    {
      FoldPreOrder(mp, v, c,nodo.LeftChild());
    }
    if(nodo.HasRightChild())
    {
      FoldPreOrder(mp, v, c,nodo.RightChild());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldPostOrder(const FoldFunctor mp,const void* v, void* c, Node& nodo)const
  {
    if(nodo.HasLeftChild())
    {
      FoldPostOrder(mp, v, c,nodo.LeftChild());
    }
    if(nodo.HasRightChild())
    {
      FoldPostOrder(mp, v, c,nodo.RightChild());
    }
    mp(nodo.Element(), v, c);
  }

  template<typename Data>
  void BinaryTree<Data>::MapInOrder(const MapFunctor mp, void* v, Node& nodo)
  {
    if(nodo.HasLeftChild())
    {
      MapInOrder(mp, v, nodo.LeftChild());
    }
    mp(nodo.Element(), v);
    if(nodo.HasRightChild())
    {
      MapInOrder(mp, v, nodo.RightChild());
    }
  }

  template<typename Data>
  void BinaryTree<Data>::FoldInOrder(const FoldFunctor mp,const void* v, void* c, Node& nodo)const
  {
    if(nodo.HasLeftChild())
    {
      FoldInOrder(mp, v, c,nodo.LeftChild());
    }
    mp(nodo.Element(), v, c);
    if(nodo.HasRightChild())
    {
      FoldInOrder(mp, v, c,nodo.RightChild());
    }
  }

/* ************************************************************************** */

}
