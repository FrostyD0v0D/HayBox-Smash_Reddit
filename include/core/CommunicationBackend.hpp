#ifndef _CORE_COMMUNICATIONBACKEND_HPP
#define _CORE_COMMUNICATIONBACKEND_HPP

#include "state.hpp"

#include "core/ControllerMode.hpp"
#include "core/InputSource.hpp"

class CommunicationBackend {
  public:
    CommunicationBackend(InputSource **input_sources, uint8_t input_source_count);
    virtual ~CommunicationBackend(){};

    InputState &CurrentInputs();
    void ScanInputs();
    void ScanInputs(InputScanSpeed input_source_filter);

    void UpdateOutputs();
    void SetGameMode(ControllerMode *gamemode);

    virtual void SendReport() = 0;

  protected:
    InputState _inputs;
    InputSource **_input_sources;
    uint8_t _input_source_count;

    OutputState _outputs;
    ControllerMode *_gamemode;

  private:
    void ResetOutputs();
};

#endif
