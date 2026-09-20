# Agent / AI coding guide

Use this file so code written here (Cursor or Claude Code) stays consistent and **human**, not AI-slop.

## Principles
- Match existing project structure and naming; do not invent parallel frameworks.
- Prefer small, reviewable diffs; one concern per PR.
- Never commit secrets (`.env`, keys, tokens). Use examples only.
- Add or update tests when changing behavior.
- Document operator-facing changes in README or PR body.

## Anti-slop (enforced by `make anti-slop` / `make auto`)
- No narrative comments that restate what the next line does.
- No `# === Helpers ===` banner comments or apologetic TODOs.
- No bare `except:` / empty `except Exception: pass`.
- No placeholder `pass  # implement later` left in merged code.
- Prefer clear names over generic `data`, `result`, `temp`, `helper2`.
- Run `ruff format` / `ruff check --fix` before finishing.
- Tools: **aislop**, **sloplint**, **agent-slop-lint**, **ruff**, optional **Strix**.

## Stack awareness (this repo = DSA practice)
- Soft gate: compileall / hooks; aislop is advisory for tutorial notes.
- Direct push to `DSA_Coding` is OK for practice notes after hooks.
- Observability for product repos is documented in `platform-ops/OBSERVABILITY.md` — not required here.

## Before finishing a task
1. For **kafka/redis**: `make local-gate` then `make anti-slop` (aislop ≥ 80) then `make auto`.
2. For **coding**: hooks + optional compile check; `ALLOW_SLOP=1 make auto REPO=coding` if shipping docs.
3. Never commit secrets (`.env`, keys, tokens).
