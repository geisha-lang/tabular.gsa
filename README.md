# data.gsa

Quantitative data toolkit for Geisha (`package name = "dataset"`, since `data` is a Geisha keyword), built on `duckdb.gsa`.

## Modules

- `dataset.series` — NaN-aware 1D `Series`: `seriesMean`, `seriesStd`, `seriesMedian`, `seriesQuantile`, tie-averaged `seriesRank`, `seriesDemean`, `seriesZscore`, `seriesCorr`, `seriesRankCorr` (Spearman RankIC), `seriesShift`, `seriesDiff`, `seriesPctChange`, `seriesRollingSum/Mean/Std`, `seriesEma`
- `dataset.panel` — 2D `(T, N)` row-major `Panel`: `panelSliceTime`, `panelCsRank/Demean/Zscore`, `panelTsShift/Diff/PctChange/RollingMean/RollingStd/Ema`, and zero-copy `mmap` binary format (`GSPNL01`) via `panelSaveBin` / `panelOpenMmap` / `mmapPanelGet`
- `dataset.frame` — Typed columnar `DataFrame` bridged to `duckdb.duckdb` & `duckdb.dsl` (`dfRun`, `dfQuery`, `dfReadParquet`, `dfReadCsv`, `dfToPanel`)

## Test

```sh
geisha test
```
