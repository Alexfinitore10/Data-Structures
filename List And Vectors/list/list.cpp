
namespace lasd {

/* ************************************************************************** */

  // Specific constructor
  template <typename Data>
  List<Data>::Node::Node(Data input){
    dato = input;
    link = nullptr;
  }

  //Copy Constructor
  template <typename Data>
  List<Data>::Node::Node(const Node& nodo){
    dato = nodo.dato;
    link = nodo.link;
  }

  //Move Constructor
  template<typename Data>
  List<Data>::Node::Node(Node&& nodo) noexcept{
    std::swap(dato, nodo.dato);
    std::swap(link, nodo.link);
  }


  /* ************************************************************************** */

  //Specific Constructor
  template <typename Data>
  List<Data>::List(const LinearContainer<Data>& var){
    for(ulong i = 0; i < var.Size(); ++i){
      InsertAtBack(var[i]);
    }
  }

  template<typename Data>
  List<Data>::~List(){
    Clear();
  }


  //Copy Constructor
  template<typename Data>
  List<Data>::List(const List& var) {
    for(ulong i = 0; i < var.Size(); ++i){
      InsertAtBack(var[i]);
    }
  }

  //Move Constructor
  template<typename Data>
  List<Data>::List(List&& var) noexcept {
    std::swap(head, var.head);
    std::swap(coda, var.coda);
    std::swap(size, var.size);
  }

  // template<typename Data>
  // List<Data>::~List() {
  //   delete Head; //rivedi
  //   delete Tail; //rivedi
  // }

  //Copy assignment
  template<typename Data>
  List<Data>& List<Data>::operator=(const List<Data>& var) {
    List<Data>* temp = new List(var);
    std::swap(*temp, *this);
    delete temp;
    return *this;
  }

  //Move assignment
  template<typename Data>
  List<Data>& List<Data>::operator=(List<Data>&& var) noexcept{
    std::swap(var.head, head);
    std::swap(var.coda, coda);
    std::swap(var.size, size);
    return *this;
  }

  //Comparison operators
  template<typename Data>
  bool List<Data> ::operator==(const List& var) const noexcept{
    if (size == var.size){
      for(ulong i=0; i<size; i++){
        if((*this)[i]!=var[i]){
          return false;
        }
      }
      return true;
    }
    else return false;
  }


  template<typename Data>
  inline bool List<Data>::operator!=(const List& var) const noexcept{
    return !(*this == var);
  }

  //Copy
  template<typename Data>
  void List<Data>::InsertAtFront(const Data& var){

    if(head == nullptr){
      struct Node* temp = new Node(var);
      head = temp;
      coda = temp;
      size++;
    }else{
      struct Node* temp = new Node(var);
      temp->link = head;
      head = temp;
      size++;
    }
  }

  //Move
  template<typename Data>
  void List<Data>::InsertAtFront(Data&& var) noexcept{

    if(head == nullptr){
      struct Node* temp = new Node(var);
      head = temp;
      coda = temp;
      size++;
    }else{
      struct Node* temp = new Node(var);
      temp->link = head;
      head = temp;
      size++;
    }
  }

  //RemoveFromFront
  template<typename Data>
  void List<Data>::RemoveFromFront(){
    if(size != 0){
      struct Node* tmp = head;
      head = head->link;
      size--;
      delete tmp;
    }else{
      throw std::length_error("Access to empty list");
    }
  }


  //FrontNRemove
  template<typename Data>
  Data List<Data>::FrontNRemove(){
    if(size != 0){
      Data tmp = head->dato;
      RemoveFromFront();
      return tmp;
    }else{
      throw std::length_error("Access to empty list");
    }
  }

  //Copy
  template<typename Data>
  void List<Data>::InsertAtBack(const Data& var){
  if(coda == nullptr){
      InsertAtFront(var);
    }else{
      struct Node* temp = new Node(var);
      coda->link = temp;
      coda = temp;
      size++;
    }
  }


  //Move
  template<typename Data>
  void List<Data>::InsertAtBack(Data&& var) noexcept{
    if(coda == nullptr){
      InsertAtFront(var);
    }else{
      struct Node* temp = new Node(var);
      coda->link = temp;
      coda = temp;
      size++;
    }
  }

  // Specific member function (inherited from Container)

  template<typename Data>
  void List<Data>::Clear() {
    int app = size;
    for(uint i=0; i<app; ++i)
    {
      RemoveFromFront();
    }
    head = nullptr;
    coda = nullptr;
    size = 0;
  }


  // Specific member functions (inherited from LinearContainer)
  template<typename Data>
  Data& List<Data>::Front() const {
    if (size != 0){
      return head->dato;
    }else{
      throw std::length_error("Access to empty list");
    }
  }



  template<typename Data>
  Data& List<Data>::Back() const{
    if (size != 0){
      return coda->dato;
    }else {
      throw std::length_error("Access to empty list");
    }
  }

  template <typename Data>
  Data& List<Data>::operator[](const ulong i) const{
    if(i == 0){
      return Front();
    }
    else if(i == size-1)
    {
      return Back();
    }
    else if(i < size)
    {
      struct Node* tmp = head;
      for(ulong j=0; j<i; j++){
        tmp = tmp->link;
      }
      return tmp->dato;
    }
    else
    {
      throw std::out_of_range("Access at index" + std::to_string(i) + "; list size " + std::to_string(size) + ".");
    }
  }

  // Specific member function inherited from MappableContainer

  template<typename Data>
  void List<Data>::MapPreOrder(const MapFunctor fun, void* par){
    for (ulong i = 0; i < size; ++i){
      fun((*this)[i], par);
    }
  }

  template<typename Data>
  void List<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    ulong i = size;
    while (i > 0){
      fun((*this)[--i], par);
    }
  }


  /* ***************************************************************** */

  // Specific member function inherited from FoldableContainer

  template<typename Data>
  void List<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
    for(ulong i = 0; i < size; ++i){
      fun ((*this)[i], par, acc);
    }
  }

  template<typename Data>
  void List<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
    ulong i = size;
    while (i > 0){
      fun((*this)[--i], par, acc);
    }
  }

}
