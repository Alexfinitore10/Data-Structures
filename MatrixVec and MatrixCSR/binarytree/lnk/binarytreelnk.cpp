
namespace lasd {

/* ************************************************************************** */

  template<typename Data>
  BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data data)
  {
    info = data;
  }

  template<typename Data>
  BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
  {
    delete leftchild;
    delete rightchild;
  }

  template<typename Data>
  Data& BinaryTreeLnk<Data>::NodeLnk::Element()noexcept
  {
    return info;
  }

  template<typename Data>
  const Data& BinaryTreeLnk<Data>::NodeLnk::Element()const noexcept
  {
    return info;
  }

  template<typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf()const noexcept
  {
    if(leftchild == nullptr && rightchild == nullptr)
    {
      return true;
    }else return false;
  }

  template<typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild()const noexcept
  {
    return (leftchild != nullptr);
  }

  template<typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild()const noexcept
  {
    return (rightchild != nullptr);
  }

  template<typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild()const
  {
    if(leftchild == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else
    return *leftchild;
  }

  template<typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild()const
  {
    if(rightchild == nullptr)
    {
      throw std::out_of_range("out_of_range");
    }else
    return *rightchild;
  }

  template<typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& ln)
  {
    if(ln.Size() != 0)
    {
      head = new NodeLnk(ln[0]);
      size++;
      FunzionedicreazioneLC(*head, ln, 0);
    }
  }

  template<typename Data>
  void BinaryTreeLnk<Data>::FunzionedicreazioneLC(NodeLnk& head, const LinearContainer<Data>& ln, uint i)
  {
    try{
    if(i > ln.Size())
    {
      return;
    }
    if(!head.HasLeftChild())
    {
      head.leftchild = new NodeLnk(ln[2*i+1]);
      size++;
      FunzionedicreazioneLC(*head.leftchild, ln, i*2+1);
    }
    if(!head.HasRightChild())
    {
      head.rightchild = new NodeLnk(ln[2*i+2]);
      size++;
      FunzionedicreazioneLC(*head.rightchild, ln, i*2+2);
    }
  }catch(...)
  {
    return;
  }
  }

  template<typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& in)
  {
    head = new NodeLnk(in.Root().Element());
    size++;
    Funzionedicreazione(*head,in.Root());
  }

  template<typename Data>
  void BinaryTreeLnk<Data>::Funzionedicreazione(NodeLnk& head, const NodeLnk& in)
  {
    if(in.HasLeftChild())
    {
      head.leftchild = new NodeLnk(in.leftchild->Element());
      size++;
      Funzionedicreazione(*head.leftchild, *in.leftchild);
    }
    if(in.HasRightChild())
    {
      head.rightchild = new NodeLnk(in.rightchild->Element());
      size++;
      Funzionedicreazione(*head.rightchild, *in.rightchild);
    }
  }

  template<typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& in)noexcept
  {
    std::swap(head, in.head);
    std::swap(size, in.size);
  }

  template<typename Data>
  BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& in)
  {
    head = new NodeLnk(in.Root().Element());
    size++;
    Funzionedicreazione(*head,in.Root());
    return *this;
  }

  template<typename Data>
  BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& in)noexcept
  {
    std::swap(head, in.head);
    std::swap(size, in.size);
    return *this;
  }

  template<typename Data>
  bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& in) const noexcept
  {
    return BinaryTree<Data>::operator==(in.Root());
  }

  template<typename Data>
  bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& in)const noexcept
  {
    return BinaryTree<Data>::operator!=(in.Root());
  }

  template<typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root()const
  {
    if(size != 0)
    {
      return *head;
    }else throw std::length_error("length_error");
  }

  template<typename Data>
  BinaryTreeLnk<Data>::~BinaryTreeLnk()
  {
    delete head;
  }

  template<typename Data>
  void BinaryTreeLnk<Data>::Clear()
  {
    size = 0;
    delete head;
    head = nullptr;
  }

/* ************************************************************************** */

}
