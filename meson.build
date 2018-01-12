project(
  'zefir',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17']
)

sources = [
  'src/main.cpp',
  'src/sql_cipher.cpp',
  'src/sql_cipher_exception.cpp'
]

sqlcipher = dependency('sqlcipher')

incdir = include_directories('inc')
#add_global_arguments('-H', language : 'cpp')
executable('zefir', sources, include_directories : incdir, dependencies : [sqlcipher])
