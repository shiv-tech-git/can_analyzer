#include <set>

#include "MsgFilter.h"

#define EDGE_MATCH_TIME 1000

MsgFilter::MsgFilter(RawMsgSequenceHandler* ms_handler): ms_handler(ms_handler) {}

std::vector<MSG_ID_T> MsgFilter::get_ids_with_pulse_near_mark(int mark) {
	std::set<MSG_ID_T> result;
	std::vector<msg_data> marks = ms_handler->marks;
	std::vector<MSG_ID_T> ids = ms_handler->get_all_ids();
	MSG_TIME_T mark_time = marks[mark].time;
	for (auto id_it = ids.begin(); id_it != ids.end(); id_it++) {
		for (int i = 0; i < 8; i++) {
			std::vector<change_point> changes = ms_handler->get_changes_sequence(*id_it, i);
			if (changes.size() == 0) continue;

			bool find_l_edge = false;
			bool find_t_edge = false;
			for (auto ch_it = changes.begin(); ch_it != changes.end(); ch_it++) {
				if (std::abs((int)ch_it->time - (int)mark_time) < EDGE_MATCH_TIME) {
					if (ch_it->edge == LEADING_EDGE) {
						find_l_edge = true;
					}
					else if (ch_it->edge == TRAILING_EDGE) {
						find_t_edge = true;
					}
				}
			}
			if (find_l_edge && find_t_edge) {
				result.insert(*id_it);
			}
		}
	}
	std::vector<MSG_ID_T> v_result;
	v_result.reserve(result.size());
	for (auto s_it = result.begin(); s_it != result.end(); s_it++) {
		v_result.push_back(*s_it);
	}
	return v_result;
}
std::vector<MSG_ID_T> MsgFilter::get_ids_with_pulse_near_marks(int mark1, int mark2) {
	std::vector<MSG_ID_T> result;
	return result;
}
std::vector<MSG_ID_T> MsgFilter::get_ids_with_leading_edge_near_mark(int mark) {
	std::set<MSG_ID_T> result;
	std::vector<msg_data> marks = ms_handler->marks;
	std::vector<MSG_ID_T> ids = ms_handler->get_all_ids();
	MSG_TIME_T mark_time = marks[mark].time;
	for (auto id_it = ids.begin(); id_it != ids.end(); id_it++) {
		for (int i = 0; i < 8; i++) {
			std::vector<change_point> changes = ms_handler->get_changes_sequence(*id_it, i);
			if (changes.size() == 0) continue;

			bool find_l_edge = false;
			for (auto ch_it = changes.begin(); ch_it != changes.end(); ch_it++) {
				if (std::abs((int)ch_it->time - (int)mark_time) < EDGE_MATCH_TIME) {
					if (ch_it->edge == LEADING_EDGE) {
						find_l_edge = true;
					}
				}
			}
			if (find_l_edge) {
				result.insert(*id_it);
			}
		}
	}
	std::vector<MSG_ID_T> v_result;
	v_result.reserve(result.size());
	for (auto s_it = result.begin(); s_it != result.end(); s_it++) {
		v_result.push_back(*s_it);
	}
	return v_result;
}
std::vector<MSG_ID_T> MsgFilter::get_ids_with_falling_edge_near_mark(int mark) {
	std::vector<MSG_ID_T> result;
	return result;
}