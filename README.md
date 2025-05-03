# 🔗 pipex

> A 42 project that recreates shell-style piping using system calls like `fork`, `pipe`, `dup2`, and `execve`.
> The goal is to understand how UNIX handles redirections and inter-process communication.

---

## 🧠 Project Objective

You must reproduce the behavior of the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Your program will:

1. Read from `infile`
2. Execute `cmd1`, then pipe its output to `cmd2`
3. Write the final output of `cmd2` to `outfile`

### Bonus:

* Handle multiple pipes (like `cmd1 | cmd2 | cmd3 | ...`)
* Support `<<` (here\_doc)

---

## ⚙️ Allowed Functions

* `open`, `close`, `read`, `write`
* `malloc`, `free`, `access`
* `dup`, `dup2`, `execve`, `exit`
* `fork`, `pipe`, `wait`, `waitpid`
* `perror`, `strerror`

---

## 🏗️ Build Instructions

```bash
make
```

This will generate the `pipex` executable.

---

## 🚀 Usage

### Mandatory:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Equivalent to:

```bash
< infile cmd1 | cmd2 > outfile
```

### Example:

```bash
./pipex infile "grep error" "wc -l" outfile
```

---

### Bonus (if implemented):

#### Multiple commands:

```bash
./pipex infile "cmd1" "cmd2" "cmd3" ... outfile
```

#### Here document:

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

Equivalent to:

```bash
<< LIMITER cmd1 | cmd2 >> outfile
```

---

## 🧪 Error Handling

* Checks if file exists and is readable
* Handles permission denied errors
* Verifies if a command is found in `PATH`
* Properly frees memory and closes FDs

---

## 📦 Features

* Manual splitting of commands and arguments
* PATH resolution using `envp`
* Robust file descriptor management
* Norm-compliant and memory-safe

---

## ✅ Norm & Constraints

* No usage of `system()`, `popen()`, or `tmpfile()`
* No leaks or zombie processes
* Norminette-checked
