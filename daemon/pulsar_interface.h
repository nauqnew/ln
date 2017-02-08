#ifndef PULSAR_INTERFACE_H
#define PULSAR_INTERFACE_H

int send_to_pulsar(const char *cdata, const char *pulsar_host, const char *pulsar_port, const char *pulsar_topic);

#endif //PULSAR_INTERFACE_H
