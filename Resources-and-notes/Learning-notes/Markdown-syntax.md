## Markdown
- [title of link](#name-of-section-of-link) : to link to different section

### Special characters
- Emspace (4 spaces): `&emsp;` (HTML entity)

### [Tables in markdown](https://www.codecademy.com/resources/docs/markdown/tables)
A table is an arrangement of data in rows and columns.

To add a table in Markdown, use the vertical line | to separate each column, and use three or more dahses --- to create each column’s header. A vertical line should also be added at either end of the row.

| Month    | Savings |
| -------- | ------- |
| January  | $250    |
| February | $80     |
| March    | $420    |

The output would look like:

Month	Savings
January	$250
February	$80
March	$420
Cell widths can vary, as shown below:

| Month | Savings |
| -------- | ------- |
| January | $250 |
| February | $80 |
| March | $420 |

The output will look exactly the same.


Text Alignment
Align text in the columns to the left, right, or center by adding a colon : to the left, right, or on both side of the dashes --- within the header row.

| Item              | In Stock | Price |
| :---------------- | :------: | ----: |
| Python Hat        |   True   | 23.99 |
| SQL Hat           |   True   | 23.99 |
| Codecademy Tee    |  False   | 19.99 |
| Codecademy Hoodie |  False   | 42.99 |

:-- means the column is left aligned.
--: means the column is right aligned.
:-: means the column is center aligned.


### Obsidian
#### Editing
- `cmd + ;` anywhere / `---` at the very beginning of a file (under the title): add properties (aliases, tags, links, ...)
- `[[target-note^section|text]]` : internal link (n.b.: Obsidian, not Markdown specific)
- `Ctrl + D` : delete current line
- `Ctrl + V` : duplicate current line
- `Ctrl + ]`: indent
- `Ctrl + [` : unindent
- `Ctrl + Click` : open Note in Current Panel via Link
- `Ctrl + Shift + Click`: open Note in New Panel via Link
#### Navigation
- `Cmd + home/end`: navigate to beginning/end of note
- `Ctrl + P`: open command pallette
- `Ctrl + O`: opens Quick Switcher
- `Ctrl + E` : toggle edit/preview modes
- `Ctrl + (+Shift) + Tab`: Next (Previous) tab