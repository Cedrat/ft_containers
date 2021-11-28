#include "../vector.hpp"
#include <string>
#include "RBTree.hpp"
 

// #define struct Node<int> * SENTRY {    Node<int> * _left = NULL;    Node<int>  *_right = NULL;    Node<int> * _parent = NULL;    bool    _color = BLACK;    int     _key = int();}

// const struct Node<int> * SENTRY
// {
//     Node<SENTRY->_right = LEAF;
//     SENTRY->_left = LEAF;
//     SENTRY->_parent = LEAF;
//     SENTRY->_color = BLACK;
//     SENTRY->_key = int();
// };

ft::vector<std::string> split_string(std::string str, std::string splitter)
{
    ft::vector<std::string> split_str;

    while (str.find(splitter) == 0)
        str.erase(0, splitter.size());
    while (str.size() > 0)
    {
        if (str.find(splitter) != std::string::npos)
        {
            split_str.push_back(str.substr(0, str.find(splitter)));
            str.erase(0, str.find(splitter) + splitter.size());
        }
        else
        {
            split_str.push_back(str.substr(0, str.size()));
            str.erase(0, str.size());
        }
        while (str.find(splitter) == 0)
            str.erase(0, splitter.size());        
    }
    return (split_str);
}

static std::string bool_color(bool color)
{
    if (color == RED)
    {
        return ("R");
    }

    if (color == BLACK)
    {
        return ("B");
    }
    return ("ERROR");
}

std::string s_substr(std::string str)
{
    return (str.substr(str.find('['), str.find(']') + 3));
}

ft::vector<std::string> tilt_tree(ft::vector<std::string> split_rbt, int depth)
{
    ft::vector<std::string> tilted_tree(depth * 2 - 1, std::string(split_rbt.size() * SPACE_FIT,' '));

    for (int i = 0; i < split_rbt.size() ; i++)
    {
        tilted_tree[(split_rbt[i].find('[')/SPACE_FIT) * 2].insert(i * SPACE_FIT, s_substr(split_rbt[i]));
    }

    for (int i = tilted_tree.size() - 1; i > 0 ; i = i-2)
    {
        for (int letter = 0; letter < tilted_tree[i].size(); letter++)
        {
            if (tilted_tree[i][letter] == ',')
                tilted_tree[i - 1][letter] = '|';
        }
    }
    
    char left_child;
    char right_child;
    int previous_pipe = 0;
    int pos_coma;
    for (int i = 0; i < tilted_tree.size() ; i++)
    {
        for (int letter = 0; letter < tilted_tree[i].size();letter++)
        {
            previous_pipe = 0;
            pos_coma = 0;
            if (tilted_tree[i][letter] == ']')
            {
                left_child = tilted_tree[i][letter+1];
                right_child = tilted_tree[i][letter+2];
                tilted_tree[i][letter+1] = ' ';
                tilted_tree[i][letter+2] = ' ';
                int p = letter;
                while (tilted_tree[i][p] != ',')
                    p--;
                pos_coma = p;
                p--;
                if (left_child == '1')
                {
                    
                    while(p >= 0 && tilted_tree[i+1][p] != '|')
                    {
                        tilted_tree[i+1][p] = '-';
                        p--;
                    }
                }
                if (right_child == '1')
                {
                    p+= 2;
                    while(tilted_tree[i+1][p] != '|')
                    {
                        tilted_tree[i+1][p] = '-';
                        p++;
                    }
                }
                if (left_child == '1' || right_child == '1')
                {
                    tilted_tree[i + 1][pos_coma] = '+';
                }
            }
        }
                std::cout << tilted_tree[i] << std::endl;
    }
    return (tilted_tree);
}

template<class T, class V>
void print_tree(Node<T,V> *head)
{
    if (head == NULL || head->isSentry())
        return ;
    std::string RBT = print_tree_str(head);

    ft::vector<std::string> split_rbt = split_string(RBT, "\n");
    tilt_tree(split_rbt, depth_tree(head));
}

template<class T, class V>
std::string print_tree_str(Node<T,V> *head,  int current_depth = 0 , std::string binary_str = std::string())
{   
    std::stringstream ss;
    if (head->_left)
    {
        binary_str += print_tree_str(head->_left, current_depth + 1);
    }
    ss << std::string(current_depth * SPACE_FIT, ' ') << "[" << head->_key << "," << bool_color(head->_color) << "]" << child(head->_left) << child(head->_right) << "\n";
    binary_str += ss.str();
    if (head->_right)
    {
        binary_str += print_tree_str(head->_right, current_depth + 1);
    }
    return (binary_str);    
}

int max(int one, int two)
{
    if (one > two)
        return (one);
    return (two);
}

template<class T, class V>
int depth_tree(Node<T,V> *head, int depth = 1)
{
    if (head)
    {
        if (head->_left && head->_right)
        {
            return (max(depth_tree(head->_left , depth + 1), depth_tree(head->_right , depth + 1)));
        }
        else if (head->_left)
        {
            return (depth_tree(head->_left, depth + 1));
        }
        else if (head->_right)
        {
            return (depth_tree(head->_right, depth + 1));
        }
    }
    return (depth);
}