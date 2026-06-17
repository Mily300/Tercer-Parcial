#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;


struct LogEntry {
    string tipo;       
    string detalle;    
    string resultado;  
};


static string logger_timestamp() {
    time_t ahora = time(nullptr);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
    return string(buf);
}


static string logger_escXML(const string& s) {
    string r;
    for (char c : s) {
        if      (c == '<')  r += "&lt;";
        else if (c == '>')  r += "&gt;";
        else if (c == '&')  r += "&amp;";
        else if (c == '"')  r += "&quot;";
        else                r += c;
    }
    return r;
}


static string logger_escJSON(const string& s) {
    string r;
    for (char c : s) {
        if      (c == '"')  r += "\\\"";
        else if (c == '\\') r += "\\\\";
        else                r += c;
    }
    return r;
}

class Logger {
private:
    string programa;
    vector<LogEntry> entradas;

public:
    Logger(const string& nombrePrograma) : programa(nombrePrograma) {}

    void registrar(const string& tipo, const string& detalle, const string& resultado) {
        entradas.push_back({tipo, detalle, resultado});
    }

    void registrar(const string& tipo, const string& detalle, float resultado) {
        ostringstream ss;
        ss << resultado;
        entradas.push_back({tipo, detalle, ss.str()});
    }

    void guardar() {
        string fecha = logger_timestamp();
        guardarJSON(fecha);
        guardarXML(fecha);
        guardarTXT(fecha);
        guardarCSV(fecha);
        cout << "\nArchivos Guardados: ejecucion.json / .xml / .txt / .csv\n";
    }

private:
    void guardarJSON(const string& fecha) {
        ofstream f("ejecucion.json");
        f << "{\n";
        f << "  \"ultima_ejecucion\": {\n";
        f << "    \"programa\": \"" << logger_escJSON(programa) << "\",\n";
        f << "    \"fecha\": \"" << fecha << "\",\n";
        f << "    \"total_operaciones\": " << entradas.size() << ",\n";
        f << "    \"operaciones\": [\n";
        for (size_t i = 0; i < entradas.size(); ++i) {
            f << "      {"
              << "\"tipo\": \""     << logger_escJSON(entradas[i].tipo)      << "\", "
              << "\"detalle\": \""  << logger_escJSON(entradas[i].detalle)   << "\", "
              << "\"resultado\": \"" << logger_escJSON(entradas[i].resultado) << "\"}";
            if (i + 1 < entradas.size()) f << ",";
            f << "\n";
        }
        f << "    ]\n";
        f << "  }\n";
        f << "}\n";
        f.close();
    }

    void guardarXML(const string& fecha) {
        ofstream f("ejecucion.xml");
        f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        f << "<ultima_ejecucion>\n";
        f << "  <programa>"          << logger_escXML(programa) << "</programa>\n";
        f << "  <fecha>"             << fecha                   << "</fecha>\n";
        f << "  <total_operaciones>" << entradas.size()         << "</total_operaciones>\n";
        f << "  <operaciones>\n";
        for (auto& e : entradas) {
            f << "    <operacion>\n";
            f << "      <tipo>"      << logger_escXML(e.tipo)      << "</tipo>\n";
            f << "      <detalle>"   << logger_escXML(e.detalle)   << "</detalle>\n";
            f << "      <resultado>" << logger_escXML(e.resultado) << "</resultado>\n";
            f << "    </operacion>\n";
        }
        f << "  </operaciones>\n";
        f << "</ultima_ejecucion>\n";
        f.close();
    }

    void guardarTXT(const string& fecha) {
        ofstream f("ejecucion.txt");
        f << "ULTIMA EJECUCION\n";
        f << "Programa          : " << programa        << "\n";
        f << "Fecha             : " << fecha           << "\n";
        f << "Total operaciones : " << entradas.size() << "\n";
        f << string(40, '-') << "\n";
        for (size_t i = 0; i < entradas.size(); ++i) {
            f << i + 1 << ". [" << entradas[i].tipo << "] "
              << entradas[i].detalle << " => " << entradas[i].resultado << "\n";
        }
        f.close();
    }

    void guardarCSV(const string& fecha) {
        ofstream f("ejecucion.csv");
        f << "programa,fecha,tipo,detalle,resultado\n";
        for (auto& e : entradas) {
            f << "\"" << programa     << "\","
              << "\"" << fecha        << "\","
              << "\"" << e.tipo       << "\","
              << "\"" << e.detalle    << "\","
              << "\"" << e.resultado  << "\"\n";
        }
        f.close();
    }
};

#endif
