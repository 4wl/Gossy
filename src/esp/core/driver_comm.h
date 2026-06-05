#pragma once

#include <windows.h>
#include <cstdint>
#include <cstddef>
#include <optional>
#include <string>

struct ProcessInfo {
	uint64_t peb;
	uint64_t base_address;
	uint64_t cr3;
};
class DriverComm {
public:
	DriverComm();
	~DriverComm();

	DriverComm(const DriverComm&) = delete;
	DriverComm& operator=(const DriverComm&) = delete;

	bool init();

	std::optional<ProcessInfo> query_process(uint32_t pid);

	bool read_memory(uint32_t pid, uint64_t addr, void* buffer, size_t size);
	bool write_memory(uint32_t pid, uint64_t addr, const void* buffer, size_t size);

	std::string  read_string(uint32_t pid, uint64_t addr, size_t max_chars);
	std::wstring read_wstring(uint32_t pid, uint64_t addr, size_t max_chars);

	template <typename T>
	T read(uint32_t pid, uint64_t addr) {
		T value{};
		read_memory(pid, addr, &value, sizeof(T));
		return value;
	}
};