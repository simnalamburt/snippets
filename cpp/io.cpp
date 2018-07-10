#include <unistd.h>
#include <fcntl.h>

#include <optional>
#include <vector>
#include <fstream>
#include <iostream>

namespace {
  constexpr auto filename { "file" };

  int write_exact(int fd, const void *buf, size_t count) {
    uintptr_t offset = 0;

    while (offset < count) {
      const auto ret = write(fd, reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(buf) + offset), count - offset);
      if (-1 == ret) { return -1; }
      offset += ret;
    }

    return 0;
  }

  bool dump() {
    const auto fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (-1 == fd) { return false; }

    const uint64_t size = 20;

    const auto ret = write_exact(fd, &size, sizeof size);
    if (-1 == ret) { return false; }

    for (uint64_t i = 0; i < size; ++i) {
      uint64_t data = i*100;

      const auto ret = write_exact(fd, &data, sizeof data);
      if (-1 == ret) { return false; }
    }
    {
      const auto ret = close(fd);
      if (-1 == ret) { return false; }
    }

    return true;
  }

  std::optional<std::vector<uint64_t>> load() {
    using namespace std;

    ifstream input { filename, ios::binary };

    uint64_t size;
    input.read(reinterpret_cast<char*>(&size), sizeof size);
    if (!input.good()) { return { }; }

    vector<uint64_t> result;
    result.reserve(size);
    for (uint64_t i = 0; i < size; ++i) {
      uint64_t value;
      input.read(reinterpret_cast<char*>(&value), sizeof value);
      if (!input.good()) { return { }; }
      result.push_back(value);
    }

    return result;
  }
}

int main() {
  using namespace std;

  if (!dump()) {
    cout << "Dump failed :/" << endl;
    return 1;
  }

  if (const auto result = load()) {
    for (const auto &value : *result) {
      cout << value << '\n';
    }
    cout.flush();
  } else {
    cout << "Malformed dump :/" << endl;
    return 1;
  }
}
