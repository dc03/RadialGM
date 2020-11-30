#ifndef REPEATEDMESSAGEMODEL_H
#define REPEATEDMESSAGEMODEL_H

#include "RepeatedModel.h"

class MessageModel;

class RepeatedMessageModel : public RepeatedModel<Message> {
  Q_OBJECT
 public:
  RepeatedMessageModel(ProtoModel *parent, Message *message, const FieldDescriptor *field);

  // RepeatedMessage models hold multiple MessageModels
  // You can access a submodel by it's position within the data structure.
  // (ie instancesModel->GetSubmodel(3))
  // FIXME: Sanity check this cast
  template <class T>
  T GetSubModel(int index) {
    return static_cast<T>(_subModels[index]);
  }

  void Swap(int /*left*/, int /*right*/) override;
  void AppendNew() override;
  void Resize(int /*newSize*/) override;
  void Clear() override;

  QVariant Data(int row, int column) const override;
  bool SetData(const QVariant &value, int row, int column) override;

  bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;
  QVariant data(const QModelIndex &index, int role) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  Qt::ItemFlags flags(const QModelIndex &index) const override;

  const std::string &MessageName() const;

  // TODO: implement dropping a message
  //virtual QMimeData *mimeData(const QModelIndexList &indexes) const override;
  //virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column,
  //const QModelIndex &parent) override;

 protected:
  QVector<MessageModel *> _subModels;
};

#endif
