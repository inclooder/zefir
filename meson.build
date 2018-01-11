project(
  'zefir',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17']
)

sources = [
  'src/main.cpp',
  'src/sql_cipher.cpp'
]

sqlcipher = dependency('sqlcipher')

incdir = include_directories('inc')
executable('zefir', sources, include_directories : incdir, dependencies : sqlcipher)
