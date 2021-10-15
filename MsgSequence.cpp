#include "MsgSequence.h"


MsgSequence::MsgSequence(uint32_t msg_id): msg_id(msg_id) {
	b_seq.reserve(8);
	for (int i = 0; i < 8; i++) {
		b_seq.push_back(new ByteSequence());
	}
}

MsgSequence::~MsgSequence() {
	for (int i = 0; i < 8; i++) {
		delete b_seq[i];
	}
}

void MsgSequence::add_msg(msg_data& msg) {
	if (msg_id != msg.id) return;

	for (int i = 0; i < 8; i++) {
		auto test = b_seq[i];
		auto tmp = std::pair<MSG_TIME_T, MSG_BYTE_T>(msg.time, msg.data[i]);
		b_seq[i]->msg_bytes.insert(tmp);
	}
}

std::vector<std::pair<uint32_t, uint8_t> > MsgSequence::get_byte_sequence(uint8_t byte_number) {
	std::vector<std::pair<uint32_t, uint8_t> > result;
	std::map<uint32_t, uint8_t> msg_bytes = b_seq[byte_number]->msg_bytes;
	result.reserve(msg_bytes.size());
	for (auto it = msg_bytes.begin(); it != msg_bytes.end(); it++) {
		result.push_back(*it);
	}
	return result;
}

void MsgSequence::find_changes() {
	for (int i = 0; i < 8; i++) {
		b_seq[i]->find_changes();
		changes_counter += b_seq[i]->changes_counter;
	}
}