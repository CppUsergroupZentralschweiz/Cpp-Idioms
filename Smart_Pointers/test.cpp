#include "double_linked_list.h"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

TEST(DoubleLinkedList, push_front)
{
    // Arrange
    DoubleLinkedList<unsigned> *list = new DoubleLinkedList<unsigned>();
    //append nodes to front of the list
    for( int i = 1 ; i < 4 ; i++) {
      list->push_front(i*1);
    }

    std::vector<unsigned> contentFwd = list->get_nodes_forward();
    std::vector<unsigned> contentRev = list->get_nodes_reverse();

    // Assert
    EXPECT_THAT(contentFwd, ElementsAre(3, 2, 1));
    EXPECT_THAT(contentRev, ElementsAre(1, 2, 3));

    delete list;
}

TEST(DoubleLinkedList, push_back)
{
    // Arrange
    DoubleLinkedList<unsigned> *list = new DoubleLinkedList<unsigned>();
    //append nodes to back of the list
    for( int i = 1 ; i < 4 ; i++) {
      list-> push_back(11 - (1 * i));
    }

    std::vector<unsigned> contentFwd = list->get_nodes_forward();
    std::vector<unsigned> contentRev = list->get_nodes_reverse();

    // Assert
    EXPECT_THAT(contentFwd, ElementsAre(10, 9, 8));
    EXPECT_THAT(contentRev, ElementsAre(8, 9, 10));

    delete list;
}

}
