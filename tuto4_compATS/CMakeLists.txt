SET(LIST4EXOS
     tuto4_compATS
  )

FOREACH(FILE ${LIST4EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} ${DGTAL_LIBRARIES} ${TutoDependencies})
ENDFOREACH(FILE)

