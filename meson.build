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
  'src/sql_cipher/statement.cpp',
  'src/framework/logger.cpp',
  'src/zefir/property.cpp',
  'src/zefir/repo.cpp',
  'src/zefir/secret.cpp',
  'src/zefir/cli/app.cpp',
  'src/zefir/cli/command.hpp',
  'src/zefir/cli/command.cpp',
  'src/zefir/cli/terminal.cpp',
  'src/zefir/cli/commands/show_password.cpp'
]

boost = dependency('boost', modules : ['thread', 'system', 'log'])
sqlcipher = dependency('sqlcipher')
readline = declare_dependency(link_args: '-lreadline')

incdir = include_directories('src')
#add_global_arguments('-H', language : 'cpp')
executable('zefir', sources, include_directories : incdir, dependencies : [boost, sqlcipher, readline])
