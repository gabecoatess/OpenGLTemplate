# Conventional Commits Guide

## Introduction
The Conventional Commits specification defines a standard style for writing commit messages. Using a consistent commit message format helps with generating automated changelogs, version management, and overall project clarity.

## Commit Message Format
A commit message should follow this basic structure:

    <type>[optional scope]: <description>

    [optional body]

    [optional footer(s)]

- **\<type\>**: The kind of change being made (see below for a list of common types).
- **[optional scope]**: A short description of the area of code affected (e.g., `auth`, `api`, `ui`).
- **\<description\>**: A brief summary of the changes in the imperative mood.
- **[optional body]**: A longer description of the change, explaining the motivation and details.
- **[optional footer(s)]**: Metadata such as issue references (e.g., `Closes #123`).

## Commit Message Types
Here are the most commonly used commit types:

- **feat:** A new feature for the user.
- **fix:** A bug fix.
- **docs:** Documentation only changes.
- **style:** Changes that do not affect the meaning of the code (e.g., formatting, missing semi-colons).
- **refactor:** A change that restructures existing code without adding a feature or fixing a bug.
- **perf:** A change that improves performance.
- **test:** Adding or updating tests.
- **build:** Changes that affect the build system or external dependencies.
- **ci:** Changes to our CI configuration files and scripts.
- **chore:** Other changes that do not modify src or test files.
- **revert:** Reverts a previous commit.

## Examples

### Feature Commit
    feat(auth): add user login endpoint

    Introduces a new endpoint allowing users to log in with either email or username.

### Bug Fix Commit
    fix(api): correct error handling for data fetch

    Fixed an issue where the API did not properly handle missing data, resulting in a crash.

### Documentation Commit
    docs(readme): update contribution guidelines

    Clarified the process for setting up the development environment and submitting pull requests.

## Guidelines for Writing Commit Messages
1. **Keep it concise:** The header should be succinct (around 50 characters) and to the point.
2. **Use the imperative mood:** Describe what the commit does (e.g., "Add", "Fix", "Update") instead of what was done.
3. **Separate header and body:** Use a blank line between the commit summary and the detailed text.
4. **Reference issues when applicable:** Include references like `Closes #` or `Fixes #` if the commit resolves an issue.
5. **Focus on one change per commit:** Each commit should address a single purpose or problem.
6. **Be clear about the context:** Use the optional scope to specify which part of the code is affected.

## Additional Tips
- **Review commit messages during code review:** A well-formed commit message is as important as clean code.
- **Automate checks when possible:** Tools like CommitLint can enforce commit message conventions.
- **Update changelogs easily:** Using conventional commits can streamline the process of generating changelogs and version bumps.

## References
- [Conventional Commits](https://www.conventionalcommits.org/)
- [Semantic Versioning](https://semver.org/)