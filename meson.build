project('image_grayscale_hystogram', 'cpp')

qt6 = import('qt6')
qt6_dep = dependency('qt6', modules: ['Core', 'Gui', 'Charts'])

sources = files(
  'imagehistogram.cpp',
  'imageviewer.cpp',
  'mainwindow.cpp',
  'window.cpp',
  'main.cpp'
)

moc_files = qt6.compile_moc(
  headers: [
    'imagehistogram.h',
    'imageviewer.h',
    'mainwindow.h',
    'window.h'
  ]
)

ui_files = qt6.compile_ui(
  sources: [
    'mainwindow.ui'
  ]
)

translations = qt6.compile_translations(
  ts_files: [
    'qtHistogram_ru_RU.ts'
  ]
)

executable('image_grayscale_histogram',
  sources,
  moc_files,
  ui_files,
  translations,
  dependencies: qt6_dep
)
