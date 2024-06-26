#pragma once
#include <stdlib.h>
#include <stdint.h>

class OutputBuffer;

class Transport
{
protected:
  // audio buffer for samples we need to send
  uint8_t *m_buffer = NULL;
  int m_buffer_size = 0;
  int m_index = 0;

  OutputBuffer *m_output_buffer = NULL;

  virtual void send() = 0;

public:
  Transport(OutputBuffer *output_buffer, size_t buffer_size);
  void add_sample(int16_t sample);
  virtual bool begin() = 0;
};