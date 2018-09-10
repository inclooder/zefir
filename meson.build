project(
  'zefir',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17']
)

sources = [
  'src/main.cpp',
  'src/passwords/generator.cpp',
  'src/sql_cipher/error.cpp',
  'src/sql_cipher/connection.cpp',
  'src/sql_cipher/result.cpp',
  'src/sql_cipher/statement.cpp',
  'src/framework/logger.cpp',
  'src/zefir/app.cpp',
  'src/zefir/property.cpp',
  'src/zefir/repo.cpp',
  'src/zefir/secret.cpp',
  'src/zefir/cli/app.cpp',
  'src/zefir/cli/command.cpp',
  'src/zefir/cli/terminal.cpp',
  'src/zefir/cli/commands/show_password.cpp',
  'src/zefir/cli/commands/new_password.cpp',
  'src/zefir/gui/app.cpp',
  'src/zefir/gui/master_password_window.cpp',
  'src/zefir/gui/secrets_window.cpp'
]

boost = dependency('boost', modules : ['thread', 'system', 'log', 'program_options'])
sqlcipher = dependency('sqlcipher')
gtkmm = dependency('gtkmm-3.0')
readline = declare_dependency(link_args: '-lreadline')

incdir = include_directories('src')
#add_global_arguments('-H', language : 'cpp')
executable('zefir', sources, include_directories : incdir, dependencies : [boost, sqlcipher, readline, gtkmm])
