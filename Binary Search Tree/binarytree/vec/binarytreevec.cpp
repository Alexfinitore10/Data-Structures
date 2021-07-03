
namespace lasd {

/* ************************************************************************** */

  template<typename Data>
  BinaryTreeVec<Data>::NodeVec::NodeVec(Data in, uint indice, Vector<NodeVec*> vec)
  {
    info = in;
    index = indice;
    vecptr = &vec;
  }

  template<typename Data>
  Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept
  {
    return info;
  }

  template<typename Data>
  const Data& BinaryTreeVec<Data>::NodeVec::Element()const noexcept
  {
    return info;
  }

  template<typename Data>
  bool BinaryTreeVec<Data>::NodeVec::IsLeaf()const noexcept
  {
    if(!HasLeftChild() && !HasRightChild())
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BinaryTreeVec<Data>::NodeVec::HasLeftChild()const noexcept
  {
    if(index*2+1 < vecptr->Size())
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BinaryTreeVec<Data>::NodeVec::HasRightChild()const noexcept
  {
    if(index*2+2 < vecptr->Size())
    {
      return true;
    }else return false;
  }

  template<typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild()const
  {
    if(HasLeftChild())
    {
      return *(vecptr->operator[](index*2+1));
    }else throw std::out_of_range("out of range");
  }

  template<typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild()const
  {
    if(HasRightChild())
    {
      return *(vecptr->operator[](index*2+2));
    }else throw std::out_of_range("out of range");
  }

  template<typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& in)
  {
    size = in.Size();
    vector.Resize(size);
    for(uint i =0; i<in.Size(); i++)
    {
      vector[i] = new NodeVec(in[i], i, vector);
      vector[i]->vecptr = &vector;
    }
  }

  template<typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& in)
  {
    size = in.Size();
    vector.Resize(in.Size());
    for(uint i = 0; i<in.Size(); i++)
    {
      vector[i] = new NodeVec(in.vector[i]->info, i, vector);
      vector[i]->vecptr = &vector;
    }
  }

  template<typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& in)noexcept
  {
    std::swap(size, in.size);
    std::swap(vector, in.vector);
    for(uint i = 0; i< size; i++)
    {
      vector[i]->vecptr = &vector;
    }
  }

  template<typename Data>
  BinaryTreeVec<Data>::~BinaryTreeVec()
  {
    Clear();
  }

  template<typename Data>
  BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& in)
  {
    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(in);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  template<typename Data>
  BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& in)noexcept
  {
    std::swap(size, in.size);
    std::swap(vector, in.vector);
    for(uint i=0; i< size; i++)
    {
      vector[i]->vecptr = &vector;
    }
    return *this;
  }

  template<typename Data>
  bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& in)const noexcept
  {
    return BinaryTree<Data>::operator==(in);
  }

  template<typename Data>
  bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& in)const noexcept
  {
    return BinaryTree<Data>::operator!=(in);
  }

  template<typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root()const
  {
    if(size !=0)
    {
      return *vector[0];
    }else throw std::length_error("length_error");
  }

  template<typename Data>
  void BinaryTreeVec<Data>::Clear()
  {
    for(uint i =0; i<vector.Size(); i++)
    {
      delete vector[i];
    }
    vector.Clear();
    size = 0;
  }

/* ************************************************************************** */

}
