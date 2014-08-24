'use strict';

var gulp = require('gulp');
var slm = require('gulp-slm');

gulp.task('slm', function() {
  var data = {
    title: 'Hello, world!',
    text: 'Hello world example for slm template.',
  };

  return gulp.src('./src/*.slm')
    .pipe(slm({ locals: data }))
    .pipe(gulp.dest('./build/'));
});

gulp.task('default', function() {
  gulp.start('slm');
});
