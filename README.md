# tabular.gsa

Polars-style unified tabular data toolkit for Geisha (`concept Frame` implemented for both `LazyFrame` and `DataFrame`, plus `Series` & `Expr`), powered by `duckdb.gsa`.

## Unified `Frame` Concept

Both `LazyFrame` and `DataFrame` implement `concept Frame`, so the exact same prefix-free pipeline verbs work on either:

```geisha
// Lazy pipeline (pushes predicates/projections into DuckDB)
let df = scanParquet("trades.parquet")
    |> dropNulls(["qty"])
    |> withColumns([alias(mul(col("price"), col("qty")), "notional")])
    |> filter(gt(col("notional"), litFloat(400.0)))
    |> groupByAgg(["sym"], [
        alias(sum(col("notional")), "total_notional"),
        alias(mean(col("price")), "avg_price"),
        alias(countAll(), "n_trades")
    ])
    |> sortDesc("total_notional")
    |> limit(10)
    |> collect?;

// Same verbs on eager in-memory DataFrame
let top1 = df
    |> sortAsc("total_notional")
    |> selectCols(["sym", "total_notional"])
    |> head(1);
```

## Modules

- `tabular.tabular` — Prefix-free `Frame` verbs (`select`, `selectCols`, `withColumns`, `filter`, `dropNulls`, `groupByAgg`, `sortAsc`, `sortDesc`, `limit`, `head`, `offset`, `unique`), `|>`, `readParquet`, `readCsv`
- `tabular.lazy` — `concept Frame`, `LazyFrame` (`scanParquet`, `scanCsv`, `scanTable`, `collect`, `sinkParquet`), and `instance Frame LazyFrame` / `instance Frame DataFrame`
- `tabular.frame` — In-memory columnar `DataFrame` (`dfHeight`, `dfWidth`, `dfDrop`, `dfWithColumn`, `dfSlice`, `dfSeries`, `dfColInt64/Str/Bool`, `dfFormat`)
- `tabular.series` — NaN-aware 1D numerical `Series`
- `tabular.expr` — Expression helpers (`alias`, `mean`, `std`, `count`, `over`)

## Test

```sh
geisha test
```
