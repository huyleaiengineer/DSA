/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using System;

public class Node{
    public int data;
    public Node next;
    
    /// Constructor
    public Node(){}
    public Node(int data)
    {
        this.data = data;
    }
    public Node(int data,Node next) 
    {
        this.data = data;
        this.next = next;
    }
}

public class LinkedList{
    public Node head;
    
    public LinkedList(){
        head = new Node();
    }
    
    public void insertAtHead(int key)
    {
        Node x = new Node(key);
        x.next = head;
        head = x;
        
    }
    
    public bool isEmpty()
    {
        return head.data == 0 && head.next == null;
    }
    
    public void removeAtHead()
    {
        if (isEmpty())
            Console.WriteLine("Empty List");
        else
            head = head.next;
    }
    
    public void ListTraverse()
    {
        for (Node x = head; x.next != null; x = x.next)
            Console.Write(x.data + " ");
        Console.WriteLine();
    }
    
    public bool isExist(int key)
    {
        for (Node x = head; x.next != null; x = x.next)
            if (x.data == key)
                return true;
        return false;
    }
    
}


class HelloWorld {
   
    
  static void Main() {
    Random random = new Random();
    LinkedList list = new LinkedList();
    for (int i = 0; i < 10; ++i)
        list.insertAtHead(random.Next(0, 10));
    
    Console.Write("Random generated List: ");
    list.ListTraverse();
    
    list.removeAtHead();
    Console.Write("After removing at head: ");
    list.ListTraverse();
    
    Console.WriteLine(list.isExist(6));
    
  }
}