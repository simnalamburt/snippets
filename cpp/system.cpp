#include <cstdlib>

int main() {
  system(R"(
cat <<EOF
asdf
sadf
asdf
EOF

printf 'ㅇㅅㅇ'; echo ';;'

if true; then
  echo '참참참'
else
  echo '거짓'
fi

echo
echo
echo

cat < /proc/self/status
)");
}
