#include "Queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(4));
}

TEST(TQueue, cant_create_queue_with_null)
{
	ASSERT_ANY_THROW(TQueue<int> q(0));
}


TEST(TQueue, create_empty_queue)
{
	TQueue<int> q(5);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_push_if_ok)
{
	TQueue<int> q(5);

	ASSERT_NO_THROW(q.Push(5));
}

TEST(TQueue, can_get_elem)
{
	TQueue<int> q(3);
	q.Push(7);

	EXPECT_EQ(7, q.Get());
}

TEST(TQueue, cant_get_if_empty)
{
	TQueue<int> q(1);

	ASSERT_ANY_THROW(q.Get());
}

TEST(TQueue, can_copy_queue)
{
	TQueue<int> q1(2);
	q1.Push(1);

	ASSERT_NO_THROW(TQueue<int> q2(q1));
}

TEST(TQueue, can_assing_queue)
{
	TQueue<int> q1(2);
	q1.Push(1);
	TQueue<int> q2(2);
	q2 = q1;

	EXPECT_EQ(1, q2.Get());
}

TEST(TQueue, test_ring_queue)
{
	TQueue<int> q(2);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	EXPECT_EQ(2, q.Get());
}

TEST(TQueue, can_get_Lenght)
{
	TQueue<int> q(2);

	EXPECT_EQ(2, q.Length());
}

TEST(TQueue, can_get_MIN_elem)
{
	TQueue<int> q(3);
	q.Push(5);
	q.Push(15);
	q.Push(8);

	EXPECT_EQ(5, q.min_elem());
}

TEST(TQueue, can_get_MAX_elem)
{
	TQueue<int> q(3);
	q.Push(5);
	q.Push(15);
	q.Push(8);

	EXPECT_EQ(15, q.max_elem());
}

TEST(TQueue, can_get_write_file)
{
	TQueue<int> q(3);
	q.Push(1);
	q.Push(14);
	q.Push(7);

	ASSERT_NO_THROW(q.file());
}
