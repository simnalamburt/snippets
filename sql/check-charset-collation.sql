SET @schema_filter = 'my_database';

-- per server
SELECT
  @@global.character_set_server,
  @@global.collation_server;

-- per db
SELECT
  schema_name,
  default_character_set_name,
  default_collation_name
FROM information_schema.schemata
WHERE schema_name LIKE @schema_filter;

-- per table
SELECT
  table_schema,
  table_name,
  character_set_name,
  collation_name
FROM information_schema.tables
INNER JOIN information_schema.collation_character_set_applicability
ON tables.table_collation = collation_character_set_applicability.collation_name
WHERE table_schema LIKE @schema_filter;

-- per column
select
  table_schema,
  table_name,
  column_name,
  character_set_name,
  collation_name
FROM information_schema.columns
WHERE table_schema LIKE @schema_filter;
