#pragma once

#include <cstddef>
#include <initializer_list>
#include <variant>
#include <vector>

#include "helper/TreeNode.h"

namespace helper {
	namespace detail {

		using TreeValue = std::variant<int, std::nullptr_t>;

		inline TreeNode* MakeTree(const std::vector<TreeValue>& values, std::size_t index) {
			if (index >= values.size() || std::holds_alternative<std::nullptr_t>(values[index])) {
				return nullptr;
			}

			TreeNode* node = new TreeNode(std::get<int>(values[index]));
			node->left = MakeTree(values, index * 2 + 1);
			node->right = MakeTree(values, index * 2 + 2);
			return node;
		}

	}  // namespace detail

	inline TreeNode* MakeTree(std::initializer_list<detail::TreeValue> values) {
		return detail::MakeTree(std::vector<detail::TreeValue>(values), 0);
	}

	inline void FreeTree(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		FreeTree(root->left);
		FreeTree(root->right);
		delete root;
	}

} // namespace helper
