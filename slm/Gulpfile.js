'use strict';

var gulp = require('gulp');
var slm = require('gulp-slm');

gulp.task('build', function() {
  return gulp.src('main.slm')
    .pipe(slm({
      locals: {
        data: 100
      }
    }))
    .pipe(gulp.dest('.'));
});

gulp.task('default', function() {
  gulp.start('build');
});
