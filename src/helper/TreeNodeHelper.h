#pragma once

#include <cstddef>
#include <initializer_list>
#include <queue>
#include <variant>
#include <vector>

#include "helper/TreeNode.h"

namespace helper {
	namespace detail {

		using TreeValue = std::variant<int, std::nullptr_t>;

		inline TreeNode* MakeTree(const std::vector<TreeValue>& values) {
			if (values.empty() || std::holds_alternative<std::nullptr_t>(values[0])) {
				return nullptr;
			}

			TreeNode* root = new TreeNode(std::get<int>(values[0]));
			std::queue<TreeNode*> nodes;
			nodes.push(root);

			std::size_t index = 1;
			while (!nodes.empty() && index < values.size()) {
				TreeNode* parent = nodes.front();
				nodes.pop();

				if (index < values.size() &&
					!std::holds_alternative<std::nullptr_t>(values[index])) {
					parent->left = new TreeNode(std::get<int>(values[index]));
					nodes.push(parent->left);
				}
				++index;

				if (index < values.size() &&
					!std::holds_alternative<std::nullptr_t>(values[index])) {
					parent->right = new TreeNode(std::get<int>(values[index]));
					nodes.push(parent->right);
				}
				++index;
			}

			return root;
		}

	}  // namespace detail

	inline TreeNode* MakeTree(std::initializer_list<detail::TreeValue> values) {
		return detail::MakeTree(std::vector<detail::TreeValue>(values));
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
