
namespace lasd {

/* ************************************************************************** */
template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& lc)
{
  for(uint i= 0; i< lc.Size(); ++i)
  {
    Insert(lc[i]);
  }
}


template <typename Data>
BST<Data>::BST(const BST<Data>& in):BinaryTreeLnk<Data>(in)
{

}

template <typename Data>
BST<Data>::BST(BST<Data>&& in)noexcept:BinaryTreeLnk<Data>(std::move(in))
{

}

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& in)
{
  BinaryTreeLnk<Data>::operator=(in);
  return *this;
}

template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& in)noexcept
{
  BinaryTreeLnk<Data>::operator=(std::move(in));
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& in) const noexcept
{
  if(size == in.Size())
  {
    BTInOrderIterator<Data> itr1(*this);
    BTInOrderIterator<Data> itr2(in);
    while(!itr1.Terminated())
    {
      if(*itr1 != *itr2)
      {
        return false;
      }
      ++itr1;
      ++itr2;
    }
    return true;
  }else
  return false;
}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& in) const noexcept
{
  return !(*this == in);
}

template <typename Data>
void BST<Data>::Insert(const Data& in)
{
  //da fare
  NodeLnk*& nd = FindPointerTo(head, in);
  if(nd == nullptr)
  {
    nd = new NodeLnk(in);
    size++;
  }
}

template <typename Data>
void BST<Data>::Insert(Data&& in)
{
  //da fare
  NodeLnk* nd = FindPointerTo(head, in);
  if(nd == nullptr)
  {
    nd = new NodeLnk(std::move(in));
  }
}

template <typename Data>
void BST<Data>::Remove(const Data& in)
{
  //da fare
  Detach(FindPointerTo(head, in));
}

template <typename Data>
const Data& BST<Data>::Min()const
{
  //da fare
  if(size != 0)
  {
    NodeLnk* a = FindPointerToMin(head);
    return a->info;
  }else throw std::length_error("Errore all'accesso del minimo");
}

template <typename Data>
Data BST<Data>::MinNRemove()
{
  //da fare
  if(size != 0)
  {
    Data a =Min();
    DetachMin(head);
    return a;
  }else throw std::length_error("Errore all'accesso del minimo");
}

template <typename Data>
void BST<Data>::RemoveMin()
{
  //da fare
  if(size != 0)
  {
    DetachMin(head);
  }else throw std::length_error("Errore all'accesso del minimo");
}

template <typename Data>
const Data& BST<Data>::Max()const
{
  //da fare
  if(size != 0)
  {
    NodeLnk* a = FindPointerToMax(head);
    return a->info;
  }else throw std::length_error("Errore all'accesso del massimo");
}

template <typename Data>
Data BST<Data>::MaxNRemove()
{
  //da fare
  if(size != 0)
  {
    Data a = Max();
    DetachMax(head);
    return a;
  }else throw std::length_error("Errore all'accesso del massimo");
}

template <typename Data>
void BST<Data>::RemoveMax()
{
  //da fare
  if(size != 0)
  {
    DetachMax(head);

  }else throw std::length_error("Errore all'accesso del massimo");
}
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& in)const
{
  NodeLnk* const* a = &FindPointerToPredecessor(head, in);
  if(a != nullptr)
  {
    return (*a)->info;
  }else throw std::length_error("Errore all'accesso del successore");
}
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& in)
{
  NodeLnk** a = &FindPointerToPredecessor(head, in);
  if(a != nullptr)
  {
    return DataNDelete(Detach(*a));
  }else throw std::length_error("Errore all'accesso del predecessore");
}
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& in)
{
  NodeLnk** a = &FindPointerToPredecessor(head, in);
  if(a != nullptr)
  {
    delete Detach(*a);
  }else throw std::length_error("Errore all'accesso del successore");
}
template <typename Data>
const Data& BST<Data>::Successor(const Data& in)const
{
  //da fare
  NodeLnk* const* a = &FindPointerToSuccessor(head, in);
  if(a != nullptr)
  {
    return (*a)->info;
  }else throw std::length_error("Errore all'accesso del successore");
}
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& in)
{
  //da fare
  NodeLnk** a = &FindPointerToSuccessor(head, in);
  if(a != nullptr)
  {
    return DataNDelete(Detach(*a));
  }else throw std::length_error("Errore all'accesso del successore");
}
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& in)
{
  NodeLnk** a = &FindPointerToSuccessor(head, in);
  if(a != nullptr)
  {
    delete Detach(*a);
  }else throw std::length_error("Errore all'accesso del successore");
}
template <typename Data>
bool BST<Data>::Exists(const Data& in) const noexcept
{
  // da fare
  return (FindPointerTo(head, in)!= nullptr);
}
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* in)
{
  // da fare
  Data dato;
  std::swap(dato, in->info);
  delete in;
  return dato;
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& in)noexcept
{
  //3 casi possibili
  if(in != nullptr)
  {
    if(in->leftchild == nullptr)
    {
      return SkipOnRight(in);
    }else if(in->rightchild == nullptr)
    {
      return SkipOnLeft(in);
    }else
    {
      NodeLnk* pointmax = DetachMax(in->leftchild);
      std::swap(pointmax->info, in->info);
      return pointmax;
    }
  }
  return nullptr;
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& in)
{
  //toglie il puntatore più piccolo - usare FindPointerToMin
  return Detach(FindPointerToMin(in));
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& in)
{
  // toglie il puntatore più grande - usare FindPointerToMax
  return Detach(FindPointerToMax(in));
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk*& in)
{
  // sposta il figlio sinistro del nodo al suo posto se ha soltanto il figlio sinistro
  if(in != nullptr)
  {
    NodeLnk* ptr = nullptr;
    std::swap(ptr, in->leftchild);
    std::swap(ptr, in);
    size--;
    return ptr;
  }
  return nullptr;
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk*& in)
{
  // sposta il figlio destr del nodo al suo posto se ha soltanto il figlio destro
  if(in != nullptr)
  {
    NodeLnk* ptr = nullptr;
    std::swap(ptr, in->rightchild);
    std::swap(ptr, in);
    size--;
    return ptr;
  }
  return nullptr;
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& in)noexcept
{
  // trova il puntatore del nodo più piccolo (tutto a sinistra)
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(in));
}
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& in) const noexcept
{
  // trova il nodo del puntatore più piccolo ma non lo tocca essendo const
  NodeLnk* const* ptr = &in;
  if(in != nullptr)
  {
    NodeLnk* current = in;
    while(current->leftchild != nullptr)
    {
      ptr = &(*ptr)->leftchild;
      current = current->leftchild;
    }
  }
  return *ptr;
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& in)noexcept
{
  // trova il puntatore del nodo più grande (tutto a destra)
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(in));
}
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& in) const noexcept
{
  // trova il puntatore del nodo più grande (tutto a destra)
  NodeLnk* const* ptr = &in;
  if(in != nullptr)
  {
    NodeLnk* current = in;
    while(current->rightchild != nullptr)
    {
      ptr = &(*ptr)->rightchild;
      current = current->rightchild;
    }
  }
  return *ptr;
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& in, const Data& dat)noexcept
{
  // Trova il puntatore da un dato sottoalbero e un dato, può restituire il nullptr se non esiste
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(in,dat));
}
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& in, const Data& dat) const noexcept
{
  // Trova il puntatore da un dato sottoalbero e un dato, può restituire il nullptr se non esiste; non può essere toccato
  NodeLnk* current = in;
  NodeLnk* const* ptr = &in;
  if(current != nullptr){
    while(current != nullptr)
    {
      if(dat < current->info)
      {
        ptr = &(*ptr)->leftchild;
        current = current->leftchild;
      }else if(dat > current->info)
      {
        ptr = &(*ptr)->rightchild;
        current = current->rightchild;
      }else
      {
        return *ptr;
      }
    }
  }
  return *ptr;
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& in, const Data& dat)noexcept
{
  // trova il puntatore al predecessore
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(in, dat));
}
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& in, const Data& dat) const noexcept
{
  // trova il puntatore al predecessore ma non lo tocca
  // NodeLnk* const* stima= nullptr;
  // if(in != nullptr)
  // {
  //   NodeLnk* const* ptr = &in;
  //   NodeLnk* current = in;
  //     while(current != nullptr)
  //     {
  //       if(current->info < dat)
  //       {
  //         stima = ptr;
  //         if(current->rightchild != nullptr)
  //         {
  //           ptr = &current->rightchild;
  //           current = current->rightchild;
  //         }
  //         else return *stima;
  //       }else
  //       {
  //         if(current->leftchild != nullptr)
  //         {
  //           if(current->info == dat)
  //           {
  //             return FindPointerToMax(current->leftchild);
  //           }else
  //           {
  //             ptr = &current->leftchild;
  //             current = current->leftchild;
  //           }
  //         }else return *stima;
  //       }
  //     }
  //   return *stima;
  // }
  // return *stima;
  NodeLnk* const* stima = nullptr;
  NodeLnk* const* curr = &in;
  NodeLnk* ptr = in;

  while(ptr != nullptr && ptr->info != dat){
    if(ptr->info < dat){
      stima = curr;
      curr = &(*curr)->rightchild;
      ptr = ptr->rightchild;
    }else{
      curr = &(*curr)->leftchild;
      ptr = ptr->leftchild;
    }
  }

  if(ptr != nullptr && ptr->leftchild != nullptr){
    stima = &FindPointerToMax((*curr)->leftchild);
  }

  return *stima;
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& in, const Data& dat)noexcept
{
  // trova il puntatore al successore
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(in, dat));
}
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& in, const Data& dat) const noexcept
{
  // trova il puntatore al successore ma non lo tocca
  // NodeLnk* const* stima = nullptr;
  // if(in != nullptr)
  // {
  //   NodeLnk* const* ptr = &in;
  //   NodeLnk* current = in;
  //   while(current != nullptr){
  //     if(current->info > dat){
  //       stima = ptr;
  //       if(current->leftchild != nullptr){
  //           ptr = &current->leftchild;
  //           current = current->leftchild;
  //       }else return *stima;
  //     }else{
  //       if(current->rightchild != nullptr){
  //         if(current->info == dat){
  //           return FindPointerToMin(current->rightchild);
  //         }else{
  //           ptr = &current->rightchild;
  //           current = current->rightchild;
  //         }
  //       }else return *stima;
  //     }
  //   }
  // }
  // return *stima;
  NodeLnk* const* stima = nullptr;
  NodeLnk* const* curr = &in;
  NodeLnk* ptr = in;

  while(ptr != nullptr && ptr->info != dat){
    if(ptr->info > dat){
      stima = curr;
      curr = &(*curr)->leftchild;
      ptr = ptr->leftchild;
    }else{
      curr = &(*curr)->rightchild;
      ptr = ptr->rightchild;
    }
  }

  if(ptr != nullptr && ptr->rightchild != nullptr){
    stima = &FindPointerToMin((*curr)->rightchild);
  }

  return *stima;
}

/* ************************************************************************** */

}
