# 📁 Core File System Module Documentation

The `file` module contains 30 native disk management mechanisms, transactional file organizers, validation checkers, and pattern search engines for Gage.

## Complete Feature Matrix

| Feature Function | Parameters | Output Medium | low-Level File Action |
| :--- | :--- | :--- | :--- |
| `gage_file_create_empty()`| None | File System | Spawns a raw target tracking file placeholder node. |
| `gage_file_delete_target()`| None | File System | Evicts target block data records cleanly from the index. |
| `gage_file_print_content()`| None | Terminal Stream| Dumps file buffer lines directly onto the user view. |
| `gage_file_write_line()` | None | File System | Truncates old bytes to overwrite fresh layout headers. |
| `gage_file_append_line()` | None | File System | Chains tracking information to existing file structures. |
| `gage_file_list_directory()`| None | Terminal Stream| Audits internal sector node listings and attribute properties. |
| `gage_file_make_dir()` | None | File System | Allocates namespace paths map markers for files tracking. |
| `gage_file_remove_dir()` | None | File System | Erases context folder tracks safely if clean of children nodes. |
| `gage_file_copy_safe()` | None | File System | Clones complete operational blocks to a secondary register. |
| `gage_file_move_safe()` | None | File System | Atomically shifts path pointers to rename tracking locations. |
| `gage_file_print_size()` | None | Terminal Stream| Counts absolute binary bytes maps metrics weights. |
| `gage_file_check_existence()`| None | Terminal Stream| Validates block pointer existence arrays in kernel indices. |
| `gage_file_check_is_dir()` | None | Terminal Stream| Flag checking if an object tracks as a folder container. |
| `gage_file_clear_content()` | None | File System | Flushes inner text matrices while preserving open pointers. |
| `gage_file_count_lines()` | None | Terminal Stream| Tallies absolute vertical text matrix rows boundaries. |
| `gage_file_print_head()` | None | Terminal Stream| Evaluates leading initialization elements of text logs. |
| `gage_file_print_tail()` | None | Terminal Stream| Evaluates trailing closure elements or newest log items. |
| `gage_file_chmod_executable()`| None| Permissions | Alters security privilege mask fields to enable binary execution. |
| `gage_file_print_stat()` | None | Terminal Stream| Audits creation timestamps metadata profiles directly. |
| `gage_file_search_text()` | None | Terminal Stream| Employs character indexing grids to isolate matching rows. |
| `gage_file_find_c_files()` | None | Terminal Stream| Traverses nested structures paths to map specific extensions. |
| `gage_file_print_working_dir()`| None| Terminal Stream| Reports current working execution environment trajectory. |
| `gage_file_compress_tar()` | None | Gzip Archive | Bundles operational directories straight into zip files. |
| `gage_file_extract_tar()` | None | File System | Decompresses packed backup streams into active tracks. |
| `gage_file_create_temp()` | None | Temp Path String| Registers unique runtime variable scratchpad locations. |
| `gage_file_print_disk_usage()`| None| Terminal Stream| Quantifies localized space metrics profiles tracking loads. |
| `gage_file_verify_md5()` | None | Hash String | Validates file data consistency against bit decay anomalies. |
| `gage_file_print_basename()`| None | Terminal Stream| Strips full absolute layout paths to return trailing names. |
| `gage_file_print_dirname()` | None | Terminal Stream| Returns the pure structural folder wrapper destination. |
| `gage_file_diff_check()` | None | Terminal Stream| Computes logical deviations profiles across distinct files. |
