# Agent / AI coding guide

Implementation / bug fix / meaningful refactor work follows the **autonomous
production-engineering workflow** in `.cursor/rules/autonomous-engineering.mdc`
and `.cursor/agents/` when changing real code. Prefer saying
`Implement this feature: …` / `Fix this bug: …`.

Use this file so notes stay consistent and **human**, not AI-slop.

## Principles
- Match existing project structure and naming; do not invent parallel frameworks.
- Prefer small, reviewable diffs; one concern per PR.
- Never commit secrets (`.env`, keys, tokens). Use examples only.

## Anti-slop
- No narrative comments that restate what the next line does.
- No banner `# ===` section comments or apologetic TODOs.
- Prefer clear names; run formatters when present.
- Tools: **aislop** (advisory for tutorial notes), **ruff** when applicable.

## Stack awareness (this repo = DSA practice)
- Soft gate: compileall / hooks; aislop is advisory for tutorial notes.
- Direct push to `DSA_Coding` is OK for practice notes after hooks.
- Product observability docs live in `platform-ops/OBSERVABILITY.md` — not required here.

## Before finishing a task
1. For **kafka/redis/inventory/orders/distributed-tracing**: `make local-gate` then
   `make anti-slop` (aislop ≥ 80) then `make auto`.
2. For **coding**: hooks + optional compile check; `ALLOW_SLOP=1 make auto REPO=coding`
   if shipping docs.
3. Never commit secrets.
