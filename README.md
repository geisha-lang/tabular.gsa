# tabular.gsa

Polars-style unified tabular data toolkit for Geisha (`LazyFrame`, `DataFrame`, `Series`, `Expr`), powered by `duckdb.gsa` under the hood.

## Modules

- `tabular.lazy` — Polars-style `LazyFrame`: `scanParquet`, `scanCsv`, `scanTable`, `lfSelect`, `lfWithColumns`, `lfFilter`, `lfDropNulls`, `lfGroupByAgg`, `lfSortAsc/Desc`, `lfLimit`, `lfJoinInner/Left`, `collect`, `sinkParquet`
- `tabular.frame` — In-memory columnar `DataFrame`: `dfReadParquet`, `dfReadCsv`, `dfHeight`, `dfWidth`, `dfSelect`, `dfDrop`, `dfWithColumn`, `dfSlice`, `dfHead`, `dfSeries`, `dfColInt64/Str/Bool`, `dfFormat`
- `tabular.series` — NaN-aware 1D numerical `Series`: `seriesMean`, `seriesStd`, `seriesMedian`, `seriesQuantile`, `seriesRank`, `seriesDemean`, `seriesZscore`, `seriesCorr`, `seriesRankCorr`, `seriesShift`, `seriesDiff`, `seriesPctChange`, `seriesRollingSum/Mean/Std`, `seriesEma`
- `tabular.expr` — Composable column/aggregate/window expressions (`eCol`, `eFloat`, `eMul`, `eGt`, `eSum`, `eMean`, `alias`, `over`, `|>`)

## Example

```geisha
let df = scanParquet("trades.parquet")
    |> lfDropNulls(["qty"])
    |> lfWithColumns([alias(eMul(eCol("price"), eCol("qty")), "notional")])
    |> lfFilter(eGt(eCol("notional"), eFloat(400.0)))
    |> lfGroupByAgg(["sym"], [alias(eSum(eCol("notional")), "total_notional"), alias(eCountAll(), "n")])
    |> lfSortDesc("total_notional")
    |> lfLimit(10)
    |> collect?;
```

## Test

```sh
geisha test
```
