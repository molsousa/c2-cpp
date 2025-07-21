#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @file Vetor.h
 * @brief Definição da classe template Vetor.
 *
 * Esta classe implementa um vetor dinâmico de tamanho fixo (até 100 elementos)
 * capaz de armazenar qualquer tipo de dado (T). Ela oferece funcionalidades
 * básicas como adição de elementos, acesso por índice, sobrecarga de operadores
 * para manipulação e métodos para obter o tamanho.
 */

/**
 * @brief Classe template para um vetor genérico.
 * @tparam T O tipo de dado dos elementos a serem armazenados no vetor.
 *
 * O Vetor armazena até 100 elementos do tipo T.
 */
template <typename T>
class Vetor {
private:
    T elementos[100]; ///< Array interno para armazenar os elementos.
    int quantidade;   ///< Quantidade de elementos atualmente no vetor.

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa um vetor vazio.
     */
    Vetor() : quantidade(0) {}

    /**
     * @brief Construtor de cópia.
     * @param outroVetor O vetor a ser copiado.
     *
     * Inicializa um novo vetor com os elementos de outro vetor.
     * Copia até o limite de 100 elementos.
     */
    Vetor(const Vetor<T>& outroVetor) : quantidade(0)
    {
        int i;
        int total_elementos = outroVetor.quantidade < 100 ? outroVetor.quantidade : 100;
        for(i = 0; i < total_elementos; ++i)
            elementos[i] = outroVetor.elementos[i];

        quantidade = total_elementos;
    }

    /**
     * @brief Adiciona um elemento em uma posição específica do vetor.
     * @param index O índice onde o elemento será adicionado.
     * @param valor O valor a ser adicionado.
     * @throws std::out_of_range Se o índice estiver fora dos limites válidos
     * (0 a quantidade atual) ou se o vetor estiver cheio.
     *
     * Se o índice for igual à quantidade atual de elementos, o elemento é
     * adicionado ao final. Caso contrário, os elementos existentes a partir
     * do índice são deslocados para a direita.
     */
    void add(int index, T valor)
    {
        if(quantidade >= 100)
            throw std::out_of_range("Erro: Vetor cheio. Nao e possivel adicionar mais elementos.");

        if(index < 0 || index > quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para adicao.");

        int i;

        // Desloca elementos para a direita se estiver inserindo no meio
        for(i = quantidade; i > index; --i)
            elementos[i] = elementos[i - 1];

        elementos[index] = valor;
        quantidade++;
    }

    /**
     * @brief Sobrecarga do operador []. Permite acesso a elementos por índice.
     * @param index O índice do elemento a ser acessado.
     * @return Uma referência ao elemento na posição especificada.
     * @throws std::out_of_range Se o índice estiver fora dos limites válidos (0 a quantidade-1).
     *
     * Permite ler e atualizar o conteúdo do vetor. Ex: `meuVetor[0] = valor;` ou `valor = meuVetor[0];`
     */
    T& operator[](int index)
    {
        if (index < 0 || index >= quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para acesso.");

        return elementos[index];
    }

    /**
     * @brief Sobrecarga do operador [] (versão const). Permite acesso de leitura a elementos por índice.
     * @param index O índice do elemento a ser acessado.
     * @return Uma referência constante ao elemento na posição especificada.
     * @throws std::out_of_range Se o índice estiver fora dos limites válidos (0 a quantidade-1).
     *
     * Usada quando o objeto Vetor é constante.
     */
    const T& operator[](int index) const
    {
        if (index < 0 || index >= quantidade) {
            throw std::out_of_range("Erro: Indice fora dos limites para acesso.");
        }
        return elementos[index];
    }

    /**
     * @brief Sobrecarga do operador +=. Adiciona um elemento ao final do vetor (append).
     * @param valor O valor a ser adicionado.
     * @return Uma referência para o próprio Vetor (para permitir encadeamento).
     * @throws std::out_of_range Se o vetor estiver cheio.
     *
     * Equivalente a `add(quantidade, valor)`.
     */
    Vetor<T>& operator+=(T valor)
    {
        add(quantidade, valor); // Usa o método add para inserir no final
        return *this;
    }

    /**
     * @brief Sobrecarga do operador = (atribuição).
     * @param outroVetor O vetor a ser atribuído.
     * @return Uma referência para o próprio Vetor (para permitir encadeamento).
     *
     * Atribui os elementos de outro vetor a este vetor, sobrescrevendo os existentes.
     * Respeita o limite de 100 elementos.
     */
    Vetor<T>& operator=(const Vetor<T>& outroVetor)
    {
        if (this != &outroVetor) { // Evita auto-atribuição
            quantidade = 0; // Reseta a quantidade atual
            int total_elementos = outroVetor.quantidade < 100 ? outroVetor.quantidade : 100;
            int i;
            for(i = 0; i < total_elementos; ++i) {
                elementos[i] = outroVetor.elementos[i];
            }
            quantidade = total_elementos;
        }
        return *this;
    }

    /**
     * @brief Retorna o elemento na i-ésima posição.
     * @param i O índice do elemento desejado.
     * @return O elemento na posição especificada.
     * @throws std::out_of_range Se o índice estiver fora dos limites válidos (0 a quantidade-1).
     *
     * Oferece uma maneira segura de acessar elementos, lançando exceção em caso de índice inválido.
     */
    T at(int i) const
    {
        if(i < 0 || i >= quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para at().");

        return elementos[i];
    }

    /**
     * @brief Retorna a quantidade de elementos adicionados ao vetor.
     * @return A quantidade atual de elementos no vetor.
     */
    int size() const
    {
        return quantidade;
    }
};

#endif // VETOR_H
