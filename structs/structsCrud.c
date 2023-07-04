#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book {
  char title[100];
  unsigned int num_pages;
  float price;
} Book;

typedef struct _student {
  char name[100];
  int age;
  Book *fav_book;
} Student;

Book *create_book(const char *title,unsigned int num_pages,float price) {
  Book *book = (Book*) calloc(1,sizeof(Book));

  strcpy(book->title,title);
  book->num_pages = num_pages;
  book->price = price;

  return book;
}

Book *copy_book(const Book *book) {
  return create_book(book->title,book->num_pages,book->price);
}

void print_book(const Book *book) {
  printf("Title: %s\n",book->title);
  printf("Num Pages: %d\n",book->num_pages);
  printf("Price: R$%.2f\n",book->price);
}

Student *create_student(const char *name,int age,const Book *fav_book) {
  Student *student = calloc(1,sizeof(Student));

  strcpy(student->name,name);
  student->age = age;
  student->fav_book = copy_book(fav_book);

  return student;
}

void destroy_book(Book **book_ref) {
  free(*book_ref);
  *book_ref = NULL;
}

void destroy_student(Student **student_ref) {
  Student *student = *student_ref;
  destroy_book(&student->fav_book);
  free(*student_ref);
  *student_ref = NULL;
}

void print_student(const Student *student) {
  printf("name: %s\n",student->name);
  printf("age: %d\n",student->age);
  puts("favorite book");
  puts("----");
  print_book(student->fav_book);
} 

int main() {
  Book *book = create_book("Human Action",789,100);
  print_book(book);
  puts("");
  book->price = 90;
  print_book(book);

  Student *ted = create_student("ted",20,book);
  print_student(ted);

  destroy_book(&book);

  print_student(ted);

  destroy_student(&ted);
  return 0;
}