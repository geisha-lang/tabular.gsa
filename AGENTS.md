# AGENTS.md — Maintenance & PR Rules (`tabular.gsa`)

Polars-style unified tabular data toolkit for Geisha (`concept Frame`, `LazyFrame`, `DataFrame`, `Series`, `Expr`), powered by `duckdb.gsa`.

## Branch, Worktree & Pull Request Workflow (No Direct Push to `main`)

`main` is protected on GitHub and gated by `Test (linux-x86_64)` and `Test (darwin-arm64)`.

1. **Never edit or commit directly on `main` in `~/code/tabular.gsa`**:
   - Keep `~/code/tabular.gsa` strictly on clean `main` (`git pull --ff-only`).
   - Always open an isolated `git worktree` on a feature/fix branch (`git -C ~/code/tabular.gsa worktree add -b <type>/<topic> <workspace>/tabular-wt origin/main`).
2. **Open a Pull Request & wait for CI before merging**:
   - Push your branch (`git push -u origin <branch>`), open a PR via `gh pr create`, and merge only after both `Test (linux-x86_64)` and `Test (darwin-arm64)` pass.
   - Do not self-merge breaking public API changes without user review.

## Engineering Rules & Verification

- Keep `concept Frame` verbs uniform across `LazyFrame` (DuckDB query pushdown) and `DataFrame` (eager in-memory columnar execution).
- Keep `geisha.lock` committed and up to date with `geisha-lang/duckdb.gsa` releases (`geisha update`).
- Verify locally before opening a PR:
  ```sh
  MACOSX_DEPLOYMENT_TARGET=14.0 geisha check
  MACOSX_DEPLOYMENT_TARGET=14.0 geisha test
  ```
