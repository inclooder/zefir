project(
  'zefir',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17']
)

sources = [
  'src/main.cpp',
  'src/sql_cipher/error.cpp',
  'src/sql_cipher/connection.cpp',
  'src/sql_cipher/result.cpp',
  'src/framework/logger.cpp',
  'src/zefir/secure_store.cpp',
  'src/zefir/secure_message.cpp'
]

boost = dependency('boost', modules : ['thread', 'system', 'log'])
sqlcipher = dependency('sqlcipher')

incdir = include_directories('src')
#add_global_arguments('-H', language : 'cpp')
executable('zefir', sources, include_directories : incdir, dependencies : [boost, sqlcipher])
