#include "Stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, cant_create_stack_with_null)
{
	ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, create_empty_stack)
{
	TStack<int> s(3);

	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, cant_push_with_no_mem)
{
	TStack<int> s(1);
	s.Push(1);

	ASSERT_ANY_THROW(s.Push(2));
}


TEST(TStack, can_push_if_ok)
{
	TStack<int> s(3);

	ASSERT_NO_THROW(s.Push(3));

}

TEST(TStack, can_get_elem)
{
	TStack<int> s(2);
	s.Push(4);

	EXPECT_EQ(4, s.Get());
}


TEST(TStack, cant_get_if_empty)
{
	TStack<int> s(1);

	ASSERT_ANY_THROW(s.Get());
}

TEST(TStack, can_copy_stack)
{
	TStack<int> s1(2);
	s1.Push(1);

	ASSERT_NO_THROW(TStack<int> s2(s1));
}

TEST(TStack, can_assing_stack)
{
	TStack<int> s1(2);
	s1.Push(1);
	TStack<int> s2(2);
	s2 = s1;

	EXPECT_EQ(1, s2.Get());
}

TEST(TStack, can_carry_out_isFull)
{
	TStack<int> s(2);
	s.Push(1);

	EXPECT_EQ(false, s.IsFull());
}

TEST(TStack, can_get_Lenght)
{
	TStack<int> s(2);

	EXPECT_EQ(2, s.Length());
}

TEST(TStack, can_get_MIN_elem)
{
	TStack<int> s(3);
	s.Push(5);
	s.Push(15);
	s.Push(8);

	EXPECT_EQ(5, s.min_elem());
}

TEST(TStack, can_get_MAX_elem)
{
	TStack<int> s(3);
	s.Push(5);
	s.Push(15);
	s.Push(8);

	EXPECT_EQ(15, s.max_elem());
}

TEST(TStack, can_get_write_file)
{
	TStack<int> s(3);
	s.Push(5);
	s.Push(15);
	s.Push(8);

	ASSERT_NO_THROW(s.file());
}